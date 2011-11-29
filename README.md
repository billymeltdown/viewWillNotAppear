# viewWillNotAppear

This is a test project created at [Zetetic](http://zetetic.net) to demonstrate a problem we've found using iOS 5 that is either a bug, or unintended use of the frameworks. We've two shipping apps, [Codebook](http://getcodebook.com) and [Strip](http://getstrip.com), that protect an "app view controller" with a "login view controller", which is presented modally at start-up and on resign active. After the app resumes active and the user logs in again, the login view is dismissed modally, revealing the app view behind it. We've been doing this since iOS 3 and have only had to make minor adjustments along the way, works pretty well. Looks better when not animated, but that's a bit beside the point. We've been doing this since iOS 3 and have only had to make minor adjustments along the way.

This works in iOS 5 unless the app receives a memory warning while it is backgrounded. When the app resumes all looks well, but after the user logs in and we dismiss the login view controller, we find that sometimes the view revealed behind it is not being drawn on screen at all.

## Demonstrating the bug

The master branch on this project already has our work-around integrated, so you'll need to check out the project at the commit right before we implemented our work-around to see the problem in action:

### 1. Clone and checkout:

    $ git clone git://github.com/billymeltdown/viewWillNotAppear.git
    $ cd ./viewWillNotAppear
    $ git checkout d856f227dc7d17bbb6d80822177918835f8050ba
    
### 2. Launch app in iPhone Simulator iOS 5
### 3. Tap the login button when it appears to display app view
### 4. Hit the Home button to background the app
### 5. Simulate Memory Warning
### 6. Tap the viewWillNotAppear icon to resume the app
### 7. Tap the login button
### 8. The revealed app view may appear blank or a black color, is not redrawn
### It doesn't always demonstrate, but more often than not in our testing

It seems to be that a race-condition is induced because we use presentModalViewController (or newer presentViewController) on resign active (same problem with dismissViewController, tried that, too), and is triggered by the memory warning when it is resuming active. This would explain why it happens sometimes and not others. Perhaps the original presentation animation isn't finished by the time the dismiss is being kicked-off?

## The Work-Around

[This is the work-around commit that first fixed the problem for us](https://github.com/billymeltdown/viewWillNotAppear/commit/eed676758f84b32ec6f148e1dfd3a32a80b9d7d3).

We're simply hiding the app view controller and not presenting the login view controller until become active. It's a good solution, but it doesn't quite feel clean.

The master branch remains the work-around demonstration. To see the fix in action, check out the master branch and repeat the steps above.

    $ git checkout master
