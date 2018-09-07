//
// Created by Sam on 8/17/2018.
//

#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::multimap;
using std::make_pair;
using std::pair;

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  multimap<int, int> segments_map;

  for (int i = 0; i < starts.size(); i++) {
    segments_map.insert(make_pair(starts[i], ends[i]));
  }

  pair<multimap<int, int>::iterator, multimap<int, int>::iterator> ret;
  multimap<int, int>::iterator it;

  for (int i = 0; i < points.size(); i++) {
    ret = segments_map.equal_range(points[i]);

    std::cout << "Searching " << points[i] << " =>";

    for (it = ret.first; it != ret.second; ++it) {
      std::cout << ' ' << it->second;
    }

    std::cout << std::endl;
  }

  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  //vector<int> cnt = naive_count_segments(starts, ends, points);
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
