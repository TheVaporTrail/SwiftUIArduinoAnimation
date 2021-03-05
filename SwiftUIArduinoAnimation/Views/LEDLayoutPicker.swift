//
//  LEDLayoutPicker.swift
//  IntegrationTest
//
//  Created by David Kaufman on 3/1/21.
//  Copyright © 2021 TheVaporTrail. All rights reserved.
//

import SwiftUI

struct LEDLayoutPicker: View {
    
    @EnvironmentObject var animateState:AnimateState

    
    var body: some View {
        Picker("", selection: $animateState.pixelLayout, content: {

            ForEach(PixelArrangement.allCases, content: { layout in
                Text(layout.name)
            })
        })
        .frame(width: 200)
    }
}

struct LEDLayoutPicker_Previews: PreviewProvider {
    static var previews: some View {
        LEDLayoutPicker()
        .environmentObject(AnimateState())
    }
}
