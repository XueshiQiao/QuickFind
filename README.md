#QuickFind

QuickFind is a Xcode Plugin to help you find/search something more quickly and more conveniently and makes Your CMD+F more powerful, in QuickFind's world, `CMD + F = (CMD + C) + (CMD + F) + (CMD + V) + (CMD + G)`

###Before:
When you want to find something in source code, you may select some text first, and press `CMD + C` to copy, then press `CMD + F` and paste, then press Enter to find, and may press `CMD + G` to find next.

![](https://raw.githubusercontent.com/qiaoxueshi/QuickFind_OLD/master/images/WithoutQuickFind.gif)

###Now using QuickFind:
Now with QuickFind, you just need to select something, and press `CMD + F`, QuickFind will open the find bar, put what you selected in the find bar and start to find the next one. You can also press `CMD + F` again and again to find the next one (just forget `CMD + G`), just like this:

![](https://raw.githubusercontent.com/qiaoxueshi/QuickFind/master/images/QuickFind.gif)

#Install and configuration
3 steps:

1. **Install QuickFind.** Install QuickFind in [Alcatraz](https://github.com/supermarin/Alcatraz) (recommend), or open up your terminal and paste this:  
    ```
        curl -fsSL https://raw.githubusercontent.com/qiaoxueshi/QuickFind/master/install.sh | sh
    ```
    
    Of course you also can clone this project, and build your own.
2. **Remove defualt Find shortcut.** Open `Xcode` - `Preferences` - `Key Binding`, remove Shortcut of 'Find' (default is CMD + F)  

3. **Add shortcut for QuickFind.** Open `System Preferences` - `KeyBoard` - `Shortcuts` - `App Shortcuts`, add a shortcut for Qucick Find like this:
    ![](https://raw.githubusercontent.com/qiaoxueshi/QuickFind_OLD/master/images/add_shortcut.png)
    
    When you open `Find` menu again, you will see:

    ![](https://raw.githubusercontent.com/qiaoxueshi/QuickFind_OLD/master/images/shortcut.png)
    
    Done, enjoy~ 
