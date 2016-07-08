#Launcher
![alt tag](http://nccastaff.bournemouth.ac.uk/jmacey/GraphicsLib/Demos/Launcher.png)


This is a simple Qt Application which will create a series of buttons to launch applications. I wrote this to help me with my lectures and talks, the image above show the buttons I use in one of my maths inspiration talks to execute a series of programs when giving a talk. It is so much easier than using the shell or a shell script.

#How it works

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

Alternativly you can pass in a file name as part of the comand line arguments. 