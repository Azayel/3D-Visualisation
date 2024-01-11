Usage:
<h3>Step One:</h3>
<p1>Clone The Repository</p1>

```

git clone https://github.com/Azayel/3D-Visualisation.git

```

<h3>Step Two:</h3>
<p1>Change Directory into the Repository</p1>

```

cd 3D-Visualisation

```

<h3>Step Three:</h3>
<p1> Activate the specific cmake file you need. Default is for Linux and is not tested. You need to get it working youself.
The Windows one should be working.</p1>
```
mv CMakeLists.txt CMakeLists.txt.Linux
mv CMakeLists.txt.Windows CMakeLists.txt      
```

<h3>Step Four:</h3>
<p1>Make A New Directory Named Build</p1>

```

mkdir build
cd build

```

<h3>Step Five:</h3>
<p1>Depending on your OS</p1>

<p1>Windows:</p1>

```

cmake -G "Unix Makefiles" ..
make 

```

<p1>Linux:</p1>

```

cmake ..
make 

```

<h3>Step Six:</h3>
<p1>Execute the created binary file<p1>

```

./Visual-3D 

```

