//
//  BOZPongRefreshControl.h
//  Ben Oztalay
//
//  Created by Ben Oztalay on 11/22/13.
//  Copyright (c) 2013 Ben Oztalay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface BOZPongRefreshControl : UIView <UIScrollViewDelegate>

/*
 *  Call this function to attach a pong refresh control to
 *  a UIScrollView. Keep in mind that it does this by adding
 *  the pong refresh control as a subview above the normal
 *  content frame (negative y value in the origin), so if you
 *  have content up there, it'll be covered up.
 *
 *  If you pass a UITableView in as the scrollView, it'll use
 *  attachToTableView instead.
 *
 *  The pong refresh control will perform the refreshAction on
 *  on the refreshTarget when the user triggers a refresh.
 */
+ (BOZPongRefreshControl*)attachToScrollView:(UIScrollView*)scrollView
                           withRefreshTarget:(id)refreshTarget
                            andRefreshAction:(SEL)refreshAction;

/*
 *  Call this function to attach a pong refresh control to
 *  a UITableView. This will replace any existing header
 *  view you already have on the table view.
 *
 *  The pong refresh control will perform the refreshAction on
 *  on the refreshTarget when the user triggers a refresh.
 */
+ (BOZPongRefreshControl*)attachToTableView:(UITableView*)tableView
                          withRefreshTarget:(id)refreshTarget
                           andRefreshAction:(SEL)refreshAction;

/*
 *  This controls the color of the paddles and ball. Use
 *  the standard backgroundColor property to set the
 *  background color.
 */
@property (strong, nonatomic) UIColor* foregroundColor;

/*
 *  This controls whether the refresh control is covered
 *  under translucent headers by a view that matches the
 *  background color of its parent UIScrollView
 */
@property (nonatomic) BOOL shouldCoverRefreshControlUnderHeader;

/*
 *  This controls how long it takes the ball to get from
 *  one paddle to the other, regardless of floor/ceiling
 *  bouncing
 */
@property (nonatomic) CGFloat totalHorizontalTravelTimeForBall;

/*
 *  Call this function when whatever loading task you're doing
 *  is done. This will reset the pong refresh control and hide
 *  it. It's also a good idea to call this if your view is
 *  going to disappear.
 */
- (void)finishedLoading;

/*
 *  Override the implementation of scrollViewDidScroll: in
 *  UIScrollViewDelegate and call this function inside of it.
 *  This lets the pong refresh control know to update its
 *  subviews as the user scrolls.
 */
- (void)scrollViewDidScroll;

/*
 *  Override the implementation of scrollViewDidEndDragging:willDecelerate:
 *  in UIScrollViewDelegate and call this function inside of it.
 *  This lets the pong refresh control know the user let go
 *  of the scroll view and causes it to check if a refresh should
 *  be triggered.
 */
- (void)scrollViewDidEndDragging;

@end
