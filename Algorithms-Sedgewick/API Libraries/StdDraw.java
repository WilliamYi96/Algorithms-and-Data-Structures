//API for the used library of static methods for standard drawing
public class StdDraw {
    //drawing methods
    static void line(double x0, double y0, double x1, double y1);
    static void point(double x, double y);
    static void text(double x, double y);
    static void circle(double x, double y, double r);
    static void filledCircle(double x, double y, double r);
    static void ellipse(double x, double y, double rw, double rh);
    static void filledEllipse(double x, double y, double rw, double rh);
    static void square(double x, double y, double r);
    static void rectangle(double x, double y, double r);
    static void filledRectangle(double x, double y, double r);
    static void polygon(double[] x, double [] y);
    static void filledPolygon(double[] x, double [] y);

    //control methods
    static void setXscale(double x0, double x1);    //reset x range to (x0, x1)
    static void setYscale(double y0, double y1);    //reset y range to (y0, y1)
    static void setPenRadius(double r); //set pen radius to r
    static void setPenColor(Color c);   //set pen color to c
    static void setFont(Font f);    //set text font to f
    static void setCancasSize(int w, int h);    //set canvas to w-by-h window
    static void clear(Color c); //clear the canvas; color it c
    static void show(int dt);   //show all; pause dt milliseconds 
}
