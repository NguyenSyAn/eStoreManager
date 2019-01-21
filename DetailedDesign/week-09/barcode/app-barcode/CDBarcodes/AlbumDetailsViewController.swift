//
//  AlbumDetailsViewController.swift
//  CDBarcodes
//
//  Created by Matthew Maher on 1/29/16.
//  Copyright © 2016 Matt Maher. All rights reserved.
//

import UIKit

class AlbumDetailsViewController: UIViewController {

    @IBOutlet weak var artistAlbumLabel: UILabel!
    @IBOutlet weak var yearLabel: UILabel!
    
    deinit {
        NotificationCenter.default.removeObserver(self)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        artistAlbumLabel.text = "Let's scan an album!"
        yearLabel.text = ""
        
        NotificationCenter.default.addObserver(self, selector: Selector(("setLabels:")), name: NSNotification.Name(rawValue: "AlbumNotification"), object: nil)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()

    }
    
    func setLabels(notification: NSNotification){
        
        // Use the data from DataService.swift to initialize the Album.
        
        let productinfo = codeinf(barecodeproduct: DataService.dataService.ALBUM_FROM_DISCOGS, barecodeproductlist: DataService.dataService.YEAR_FROM_DISCOGS)
        
        artistAlbumLabel.text = "\(String(describing: productinfo.barecode))"
        yearLabel.text = "\(String(describing: productinfo.barecodelist))"
    }
}
