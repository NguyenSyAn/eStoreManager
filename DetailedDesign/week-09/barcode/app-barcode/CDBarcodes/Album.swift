//
//  Album.swift
//  CDBarcodes
//
//  Created by Matthew Maher on 1/29/16.
//  Copyright © 2016 Matt Maher. All rights reserved.
//

import Foundation

class codeinf {
        
    private(set) var barecode: String!
    private(set) var barecodelist: String!
    
    init(barecodeproduct: String, barecodeproductlist: String) {
        
        // Add a little extra text to the album information.
        
        self.barecode = "Album: \n\(barecodeproduct)"
        self.barecodelist = "Released in: \(barecodeproductlist)"
    }
}
