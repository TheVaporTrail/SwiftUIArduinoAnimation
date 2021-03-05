//
//  ContentView.swift
//  IntegrationTest
//
//  Created by David Kaufman on 2/24/21.
//  Copyright © 2021 TheVaporTrail. All rights reserved.
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        VStack {
            Spacer()
            
            LEDsView()
            .padding(10)
            .background(Color.black)
            .cornerRadius(25)
            .padding(10)

            Spacer()
            
            LEDLayoutPicker()
            .padding(.bottom)
        }
    }
}


struct ContentView_Previews: PreviewProvider {
    
    static var previews: some View {
        
        return ContentView()
                .environmentObject(AnimateState())
    }
}
