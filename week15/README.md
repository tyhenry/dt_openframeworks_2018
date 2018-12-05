# Week 15


# Notes

notes on OpenCV:
---------------
 
OpenCV is the most popular library for computer vision - it's used by everyone from academics to Snapchat engineers to artists.

It's a huge, powerful collection of image processing and machine learning algorithms written in C++.

oF works well with OpenCV, through 2 addons:

 + **ofxOpenCv** adds the OpenCV library to your project  
    this addon comes with oF

 + **ofxCv** provides an elegant interface to bridge oF and OpenCV  
    download / learn about ofxCv here:
    https://github.com/kylemcdonald/ofxCv

`ofxCv` has a ton of functions and classes that work beautifully out of the box in oF.  It can handle object detection, tracking, blob detection, and much more.

In addition, it can convert native oF classes to native OpenCV classes, so you can work directly with any OpenCV algorithms.  

Here's an example of how to convert an `ofImage` to a native OpenCV `Mat` object (an image "matrix"):  

```c++

   ofImage img;
   img.load("image.png");
   Mat imgMat = toCv(img);   ofx::toCv(ofImage)

   // now you can use the image as a Mat with any OpenCV algorithm
```