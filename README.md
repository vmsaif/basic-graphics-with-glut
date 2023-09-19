# Basic Graphics with GLUT

[![Hits](https://hits.sh/github.com/vmsaif/basic-graphics-with-glut.svg?label=Visits&color=100b75)](https://hits.sh/github.com/vmsaif/basic-graphics-with-glut/)

This project showcases various basic graphics techniques using GLUT. Users can choose from four distinct programs, each demonstrating a unique graphics technique or transformation.

## Features

- **Anti Aliasing Technique**: Draws houses with smoother edges using the anti-aliasing technique.
- **Translation and Rotation**: Demonstrates the translation and rotation transformations on houses.
- **Color Gradient**: Renders a rectangle with vertices colored in red, green, blue, and yellow, creating a gradient effect.
- **Complex Transformations**: Displays houses transformed using translation, scaling, and rotation.

## Requirements

### This Repository

Clone this repository to your local machine with:

```bash
git clone https://github.com/vmsaif/basic-graphics-with-glut
```

### Visual Studio

Ensure you have Visual Studio installed. If not, download it from [Visual Studio Official Website](https://visualstudio.microsoft.com/).

### GLUT Library

This project requires the OpenGL library or `glut.h`. The easiest way to set it up in Visual Studio is as follows:

1. Navigate to the directory where you cloned the project.
2. Open the `basic-graphics-in-opengl.sln` file in Visual Studio.
3. Click on `Project` in the menu bar.
4. Select `Manage NuGet Packages`.
5. Click on the "Browse" tab.
6. Search for "freeglut".
7. Select "nupengl.core" (which includes glut.h) and click `Install`.

## Running the Project

1. Open the project in Visual Studio.
2. Press `F5` or choose the `Run Without Debugging` option.
3. Follow the on-screen prompts to select and run a graphics program.

## Programs

1. **Using Anti Aliasing Technique**: Draws two houses with rotation and one house using the anti-aliasing technique for smoother edges.
2. **Translating and Rotating**: Renders a house five times, showcasing translation and rotation transformations.
3. **Color Gradient**: Displays a rectangle with vertices set to red, green, blue, and yellow, creating a gradient effect.
4. **Houses with Transformations**: Illustrates eight houses with triangle roofs and floors, transformed using translation, scaling, and rotation. The houses are crafted using basic shapes.

