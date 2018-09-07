import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class CoveringSegments {

    private static int[] optimalPoints(Segment[] segments) {
        Arrays.sort(segments, new Comparator<Segment>() {
            @Override
            public int compare(Segment o1, Segment o2) {
                return Integer.compare(o1.end, o2.end);
            }
        });

        ArrayList<Integer> pts = new ArrayList<>();

        int cnt = 0;
        for (int i = 0; i < segments.length; i++) {
            int point = segments[i].end;

            //points[cnt] = point;
            pts.add(point);

            for (int j = i+1; j < segments.length; j++) {
                if (segments[j].start <= point && point <= segments[j].end) {
                    i++;
                } else {
                    break;
                }
            }

            cnt++;
        }

        int[] points = new int[pts.size()];
        for (int i = 0; i < pts.size(); i++) {
            points[i] = pts.get(i);
        }

        return points;
    }

    private static class Segment {
        int start, end;

        Segment(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Segment[] segments = new Segment[n];
        for (int i = 0; i < n; i++) {
            int start, end;
            start = scanner.nextInt();
            end = scanner.nextInt();
            segments[i] = new Segment(start, end);
        }
        int[] points = optimalPoints(segments);
        System.out.println(points.length);
        for (int point : points) {
            System.out.print(point + " ");
        }
    }
}