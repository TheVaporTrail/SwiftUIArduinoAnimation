//
//  AnimateState.swift
//  IntegrationTest
//
//  Created by David Kaufman on 3/1/21.
//  Copyright © 2021 TheVaporTrail. All rights reserved.
//

import Foundation
import SwiftUI
import Combine

let pi:CGFloat = 3.141592

enum LayoutStyle {
    case Ring
    case Strip
}

enum PixelArrangement: String, CaseIterable, Hashable, Identifiable {
    
    case Ring16 = "Ring, 16 LEDs"
    case Ring24 = "Ring, 24 LEDs"
    case Ring32 = "Ring, 32 LEDs"
    case Ring60 = "Ring, 60 LEDs"
    case Strip100 = "Strip, 100 LEDs"
    case Strip144 = "Strip, 144 LEDs"

    var id: PixelArrangement { self }
    var name: String { self.rawValue }
}

// Create a color using a 24bit hex code, eg, 0xFF0000 for red
extension Color {
    init(rgb:Int) {
        let ri = ((rgb >> 16) & 0xff)
        let gi = ((rgb >> 8) & 0xff)
        let bi = (rgb & 0xff)

        let rd = Double(ri)/255.0
        let gd = Double(gi)/255.0
        let bd = Double(bi)/255.0

       self.init(red: rd, green:gd, blue: bd);
    }
}

final class AnimateState: ObservableObject {

    let objectWillChange = PassthroughSubject<AnimateState,Never>() // I forgot what this does...
 
    @Published var pixelLayout = PixelArrangement(rawValue:UserDefaults.standard.string(forKey: "arrangement") ?? "Strip, 100 LEDs")! {
        didSet {
            objectWillChange.send(self)
            updateValues()
            AnimateWrapper().setPixelCount(UInt32(pixelCount))
            UserDefaults.standard.set(pixelLayout.name, forKey: "arrangement")
        }
    }
    
    @Published var pixelColors:[Int] = Array(repeating: 0, count: 500)

    // Derived values
    @Published var layoutStyle = LayoutStyle.Ring
    @Published var pixelCount = 32
    @Published var ringRadius:CGFloat = 100.0
    @Published var angleDelta:CGFloat = (2*3.14159)/32

    // Constants
    let ledSize:CGFloat = 15.0
    
    let stripStraightCount = 18
    let stripCurveCount = 4
    let stripPixelSpacing:CGFloat = 20.0
	// It would be better to use the pixel spacing and the curve count
	// to calculate the row spacing
    let stripRowSpacing:CGFloat = 50.0

    init() {
        updateValues()
		AnimateWrapper().setup()
        AnimateWrapper().setPixelCount(UInt32(pixelCount))
    }
    
    func updateValues() {
        // There's probably a better way to do this...
        switch pixelLayout {
            case PixelArrangement.Ring16:
                layoutStyle = LayoutStyle.Ring
                pixelCount = 16
            case PixelArrangement.Ring24:
                layoutStyle = LayoutStyle.Ring
                pixelCount = 24
            case PixelArrangement.Ring32:
                layoutStyle = LayoutStyle.Ring
                pixelCount = 32
            case PixelArrangement.Ring60:
                layoutStyle = LayoutStyle.Ring
                pixelCount = 60
            case PixelArrangement.Strip100:
                layoutStyle = LayoutStyle.Strip
                pixelCount = 100
            case PixelArrangement.Strip144:
                layoutStyle = LayoutStyle.Strip
                pixelCount = 144
        }
        
        // Somewhat arbitrary...the original layout had 32 LEDs with a radius of 100, so this
        // preserves that and scales for different LED counts. It would make more sense to use
        // something like LED spacing
        ringRadius = (100.0 * CGFloat(pixelCount) / 32)
        
        angleDelta = (2*pi)/CGFloat(pixelCount)
    }
    
    func calcRingFrameWidth() -> (CGFloat) {
        return ringRadius * 2.5
    }

    func calcRingFrameHeight() -> (CGFloat) {
        return ringRadius * 2.5
    }

    func calcStripFrameWidth() -> (CGFloat) {
        return CGFloat(stripStraightCount + stripCurveCount + 2) * stripPixelSpacing
    }

    func calcStripFrameHeight() -> (CGFloat) {
        let rows = pixelCount / (stripStraightCount + stripCurveCount)
        return CGFloat(rows + 2) * stripRowSpacing
    }

    func calcRingPosition(_ ringPosition:Int) -> (CGPoint) {
        let angle = CGFloat(ringPosition) * angleDelta
        let x:CGFloat = ledSize/2 + ringRadius * cos(angle)
        let y:CGFloat = ledSize/2 + ringRadius * sin(angle)
        return CGPoint(x:x, y:y)
    }

    func calcStripPosition(_ stripPosition:Int) -> (CGPoint) {
        
        // A row is considered the horizontal pixels and the pixels turning the corner on one side
        let pixelsPerRow = stripStraightCount + stripCurveCount
        
        
        let col = stripPosition % pixelsPerRow
        let row = stripPosition / pixelsPerRow
        let odd = ((row % 2) == 1)
        var x:CGFloat
        var y:CGFloat
        
        y = CGFloat(row) * stripRowSpacing
        
        if (col < stripStraightCount) {
            x = CGFloat(col) * stripPixelSpacing
        }
        else {
            let ctrX = CGFloat(stripStraightCount) * stripPixelSpacing - stripPixelSpacing/2
            let ctrY = y + stripRowSpacing/2
            let r = stripRowSpacing/2
            x = CGFloat(stripStraightCount - 2) * stripPixelSpacing

            let c = CGFloat(col - stripStraightCount)

            y += (c + 0.5) * stripRowSpacing/CGFloat(stripCurveCount)

            let angleDelta = pi/CGFloat(stripCurveCount)
            let angle = pi/2 - (c + 0.5) * angleDelta

            x = ctrX + r * cos(angle)
            y = ctrY - r * sin(angle)
        }
        
        // Reverse the direction for every other row
        if (odd) {
            x = CGFloat(stripStraightCount - 1) * stripPixelSpacing - x
        }
        
        // Position within the view
        let offsetX:CGFloat = calcStripFrameWidth()/2 - 60
        let offsetY:CGFloat = calcStripFrameHeight()/2 - 50
        x = x - offsetX
        y = y - offsetY

        return CGPoint(x:x, y:y)
    }

}




