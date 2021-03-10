int GetMid(vector<int>& arr, int begin, int end) {
      int mid = (begin + end) / 2;
      if (arr[begin] > arr[mid]) {
            if (arr[mid] > arr[end])
                  return mid;
            else if (arr[begin] > arr[end])
                  return end;
            return begin;
      }
      else {
            if (arr[mid] < arr[end])
                  return mid;
            else if (arr[end] > arr[begin])
                  return end;
            return begin;
      }
}

int PartSort(vector<int>& arr, int begin, int end) {
      int mid = GetMid(arr, begin, end);
      swap(arr[end], arr[mid]);
      int key = arr[end];
      int keyIndex = end;
      while (begin < end) {
            while (begin < end && arr[begin] <= key) {
                  ++begin;
            }
            while (begin < end && arr[end] >= key) {
                  --end;
            }
            swap(arr[begin], arr[end]);
      }
      swap(arr[begin], arr[keyIndex]);
      return begin;
}

void QuickSort(vector<int>& arr) {
      if (arr.size() <= 1)
            return;
      stack<int> st;
      int mid = PartSort(arr, 0, arr.size() - 1);
      if (mid - 1 > 0) {
            st.push(0);
            st.push(mid-1);
      }
      if (mid + 1 < arr.size() - 1) {
            st.push(mid + 1);
            st.push(arr.size() - 1);
      }

      while (!st.empty()) {
            int right = st.top();
            st.pop();
            int left = st.top();
            st.pop();

            int keyindex = PartSort(arr, left, right);
            if (keyindex - 1 > left) {
                  st.push(left);
                  st.push(keyindex-1);
            }
            if (keyindex + 1 < right) {
                  st.push(keyindex + 1);
                  st.push(right);
            }
      }

}
