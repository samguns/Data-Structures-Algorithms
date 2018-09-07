//
// Created by Sam on 8/10/2018.
//

#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;
using std::sort;

struct Segment {
  int start, end;
};

static bool CompareSegment(Segment& i, Segment& j) {
  return (i.end < j.end);
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;

  sort(segments.begin(), segments.end(), CompareSegment);

  for (int i = 0; i < segments.size(); i++) {
    int point = segments[i].end;

    points.push_back(point);

    for (int j = i+1; j < segments.size(); j++) {
      if (segments[j].start <= point && point <= segments[j].end) {
        i++;
      } else {
        break;
      }
    }
  }

  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
