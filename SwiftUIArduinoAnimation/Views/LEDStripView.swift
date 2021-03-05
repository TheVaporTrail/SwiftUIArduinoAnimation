//
//  LEDStripView.swift
//  IntegrationTest
//
//  Created by David Kaufman on 3/1/21.
//  Copyright © 2021 TheVaporTrail. All rights reserved.
//

import SwiftUI

struct LEDStripView: View {
    @EnvironmentObject var animateState:AnimateState

    var body: some View {
        ZStack {
            ForEach(0...animateState.pixelCount-1, id:\.self) {idx in
                Circle()
                .foregroundColor(Color(rgb: self.animateState.pixelColors[idx]))
                .overlay(
                    RoundedRectangle(cornerRadius: size/2)
                    .stroke(Color(red: 0.5, green: 0.5, blue: 0.5, opacity: 1.0), lineWidth: 0.25)
                )
                .position(self.animateState.calcStripPosition(idx))
                .frame(width: size, height: size)
            }
        }
        .frame(width:self.animateState.calcStripFrameWidth(), height:self.animateState.calcStripFrameHeight())
    }
}

struct LEDStripView_Previews: PreviewProvider {
    static var previews: some View {
        LEDStripView()
    }
}
