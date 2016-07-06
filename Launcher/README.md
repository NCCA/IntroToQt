#Launcher

This is a simple Qt Application which will create a series of buttons to launch applications.

It will search the current working directory for a file called launcher.cfg which contains the following data

```
[button text] [path for exe] [exe name]

# is used for comments and ignored
```

Each line will create a new button in order described in the file. 

A sample file can be found [here](https://github.com/NCCA/IntroToQt/blob/master/Launcher/launcher.cfg) (note it will need to be changed to reflect changes on your own system) 