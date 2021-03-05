//
//  LEDsView.swift
//  IntegrationTest
//
//  Created by David Kaufman on 3/1/21.
//  Copyright © 2021 TheVaporTrail. All rights reserved.
//

import SwiftUI

struct LEDsView: View {

    @EnvironmentObject var animateState:AnimateState
    
    var timer = Timer.publish(every: 0.1, on: .main, in: .common).autoconnect()

    var body: some View {
        ZStack {
            if (self.animateState.layoutStyle == LayoutStyle.Ring) {
                LEDRingView()
            }
            if (self.animateState.layoutStyle == LayoutStyle.Strip) {
                LEDStripView()
            }
        }
        .onReceive(self.timer) { input in
             AnimateWrapper().step()
             let cpixels:UnsafeMutablePointer<UInt32> = AnimateWrapper().render()
             for n in 0...self.animateState.pixelCount-1 {
                 self.animateState.pixelColors[n] = Int(cpixels[n])
             }
            self.animateState.objectWillChange.send(self.animateState)
        }

    }
}

struct LEDsView_Previews: PreviewProvider {
    static var previews: some View {
        LEDsView().environmentObject(AnimateState())
    }
}
