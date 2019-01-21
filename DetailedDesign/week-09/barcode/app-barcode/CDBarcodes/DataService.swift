//
//  DataService.swift
//  CDBarcodes
//
//  Created by Matthew Maher on 1/29/16.
//  Copyright © 2016 Matt Maher. All rights reserved.
//

import Foundation
import Alamofire
import SwiftyJSON

class DataService {
    
    static let dataService = DataService()
    
    private(set) var ALBUM_FROM_DISCOGS = ""
    private(set) var YEAR_FROM_DISCOGS = ""
    
    static func searchAPI(codeNumber: String) {
        
        // The URL we will use to get out album data from Discogs
        
        _ = "\(DISCOGS_AUTH_URL)\(codeNumber)&?barcode&key=\(DISCOGS_KEY)&secret=\(DISCOGS_SECRET)"
        
        let url = "https://myurl.com/posts"
        Alamofire.request(url).responseJSON { response in
            switch response.result {
            case .success:
                print(response)
            case .failure(let error):
                print(error)
            }
                
                var json = JSON(response.result.value!)
                
                let albumArtistTitle = "\(json["results"][0]["title"])"
                let albumYear = "\(json["results"][0]["year"])"
                
                self.dataService.ALBUM_FROM_DISCOGS = albumArtistTitle
                self.dataService.YEAR_FROM_DISCOGS = albumYear
                
                // Post a notification to let AlbumDetailsViewController know we have some data.
                
            NotificationCenter.default.post(name: NSNotification.Name(rawValue: "AlbumNotification"), object: nil)
        }
    }
}
