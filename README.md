Mojo - 3D editor
================

Mojo is an C++ Qt4 based application, that provides the necessary tools for 3D models creation. Basically Mojo allows
to read from *.xml files with particular tags and generate a 3D model.

Installation
------------
Before compile the Mojo project you need the Qt4 library installed on your computer, so if you don't have the 
Qt4 library installed, you can install it by following the instructions below.

### GNU/Linux Debian distributions ###
Open a shell by pressing Ctrl+Alt+T and paste the following command:

	sudo apt-get install libqt4-core libqt4-dev libqt4-gui qt4-dev-tools

This will automatically install and compile the Qt4 library and now you will be able to compile the Mojo project.
For doing this you have to move to the folder with the project and execute the following command:

	make -j4

The ``-j4`` option is optional, but if your computer have more then one core it's better to use this option.
