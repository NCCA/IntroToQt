#Launcher
![alt tag](http://nccastaff.bournemouth.ac.uk/jmacey/GraphicsLib/Demos/Launcher.png)


This is a simple Qt Application which will create a series of buttons to launch applications.

It will search the current working directory for a file called launcher.json which contains the following data

```
{
  "Programs": [
  	{
    "ButtonText": "Ball 1",
     "Path" : "/Users/jmacey/teaching/Talks/MathsInsperation/Code/2D/Pythag",
     "Exe"  : "Pythag",
     "arguments" : ""
    }
    ]
}
```

Each line will create a new button in order described in the file. 

A sample file can be found [here](https://github.com/NCCA/IntroToQt/blob/master/Launcher/launcher.json) (note it will need to be changed to reflect changes on your own system) 