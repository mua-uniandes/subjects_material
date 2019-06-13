package mua.uniandes.edu.co;

import java.awt.geom.Point2D;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Stack;

public class ConvexHull {
    private Stack<Point2D> hull = new Stack<Point2D>();
    private Point2D[] points;

    /**
     * Constructs an object that will contain the convex hull of the given points.
     * Executes Graham's Scan algorithm.
     * <p>
     * Based on the algorithm given in "Introduction to Algorithms," 3rd edition, pp. 1031<br>
     * Thomas H. Cormen et. al.
     *
     * @param pts	array of points from which to compute the convex hull
     */
    public ConvexHull(Point2D[] pts) {
        this.points = pts;

        Arrays.sort(points, new PointComparator());

        //Minimum y point, or if tie, leftmost point.
        hull.push(points[0]);

        //Now, sort by polar angle around p0.
        Arrays.sort(points, new PointComparator(points[0]));

        hull.push(points[1]);
        hull.push(points[2]);

        for(int i = 3; i < points.length; ++i) {
            Point2D top = hull.peek();
            Point2D nextToTop = hull.get(hull.size() - 2);

            while(polarAngle(points[i], nextToTop, top) >= 0 && hull.size() >= 3) {
                hull.pop();
                top = hull.peek();
                nextToTop = hull.get(hull.size() - 2);
            }

            hull.push(points[i]);
        }
    }

    /**
     * Returns the computed convex hull points.
     */
    public Point2D[] getHull() {
        Point2D[] pointArray = new Point2D[]{};
        return hull.toArray(pointArray);
    }

    /**
     * Returns the polar angle of p0, p1, and p2.
     */
    private double polarAngle(Point2D p0, Point2D p1, Point2D p2) {
        //If this cross product is positive, then p0p1 is clockwise from p0p2; if negative, it is counter-clockwise.
        return (p1.getX() - p0.getX()) * (p2.getY() - p0.getY()) - (p2.getX() - p0.getX()) * (p1.getY() - p0.getY());
    }
}

class PointComparator implements Comparator<Point2D> {
    private Point2D origin;

    public PointComparator() {    }

    public PointComparator(Point2D origin) {
        this.origin = origin;
    }

    /**
     * Compares its two arguments for order. Returns a negative integer, zero, or a
     * positive integer as the first argument is less than, equal to, or greater than
     * the second. If an origin was specified, comparison will be based on polar
     * angle. Otherwise, it is based upon position.
     *
     * @param p1	the first point to be compared
     * @param p2	the second point to be compared
     * @return		a negative integer, zero, or a positive integer as the first argument is less than, equal to, or greater than the second
     */
    @Override
    public int compare(Point2D p1, Point2D p2) {
        double angle;
        if(origin != null)
            angle = (p1.getX() - origin.getX()) * (p2.getY() - origin.getY()) - (p2.getX() - origin.getX()) * (p1.getY() - origin.getY());
        else
            angle = p1.getX()*p2.getY() - p1.getY()*p2.getX();
        return (int) angle;
    }
}