//
//  WLSiteDelegate.h
//  Welly
//
//  Created by K.O.ed on 09-9-29.
//  Copyright 2009 Welly Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#define floatWindowLevel kCGStatusWindowLevel+1

@class WLSite;

@protocol WLSitesObserver

- (void)sitesDidChanged:(NSArray *)sitesAfterChange;

@end


@interface WLSitesPanelController : NSObject {
	/* Sites Array */
    NSMutableArray *_sites;
    IBOutlet NSArrayController *_sitesController;
	
	/* Site Panel Outlets */
    IBOutlet NSPanel *_sitesPanel;
    IBOutlet NSTableView *_tableView;
    IBOutlet NSTextField *_siteNameField;
    IBOutlet NSTextField *_siteAddressField;

    IBOutlet NSPopUpButton *_proxyTypeButton;
    IBOutlet NSTextField *_proxyAddressField;
    IBOutlet NSTextField *_idBlacklistField;
    
    /* Password Window Outlets */
    IBOutlet NSPanel *_passwordPanel;
    IBOutlet NSSecureTextField *_passwordField;
	
	/* Observers */
	NSMutableArray *_sitesObservers;
}
@property (readonly) NSArray *sites;

/* Accessors */
+ (WLSitesPanelController *)sharedInstance;
+ (void)addSitesObserver:(NSObject<WLSitesObserver> *)observer;
+ (NSArray *)sites;
+ (WLSite *)siteAtIndex:(NSUInteger)index;
- (unsigned)countOfSites;

/* Site Panel Actions */
- (IBAction)connectSelectedSite:(id)sender;
- (IBAction)closeSitesPanel:(id)sender;

- (IBAction)proxyTypeDidChange:(id)sender;
- (void)openSitesPanelInWindow:(NSWindow *)mainWindow;
- (void)openSitesPanelInWindow:(NSWindow *)mainWindow 
				   andAddSite:(WLSite *)site;

/* password window actions */
- (IBAction)openPasswordDialog:(id)sender;
- (IBAction)confirmPassword:(id)sender;
- (IBAction)cancelPassword:(id)sender;

@end
