#include "search.h"

int f_findFirstInRow(const std::vector<int>& row, int m, int k){
    int left = 0;
    int right = m - 1;
    int ans = -1;

    while(left <= right){
        int mid = (left + right) / 2;

        if(row[mid] == k){
            ans = mid;
            right = mid - 1;
        }
        else if(row[mid] < k){
            left = mid + 1;
        }
        else 
            right = mid - 1;
    }
    return ans;
}

int f_findLastInRow(const std::vector<int>& row, int m, int k){
    int left = 0;
    int right = m - 1;
    int ans = -1;

    while(left <= right){
        int mid = (left + right) / 2;

        if(row[mid] == k){
            ans = mid;
            left = mid + 1;
        }
        else if(row[mid] < k){
            left = mid + 1;
        }
        else 
            right = mid - 1;
    }
    return ans;
}


Result f_iterativeFirst(const std::vector<std::vector<int>>& matrix, int n, int m,int k){
    Result ans;
    ans.found = false;
    ans.row = -1;
    ans.column = -1;

    for(int i = 0; i < n; i++){
        int pos = f_findFirstInRow(matrix[i], m, k);
        if(pos != -1){
            ans.found = true;
            ans.row = i;
            ans.column = pos;
            return ans;
        }
    }
    return ans;
}

Result f_iterativeLast(const std::vector<std::vector<int>>& matrix, int n, int m,int k){
    Result ans;
    ans.found = false;
    ans.row = -1;
    ans.column = -1;

    for(int i = n - 1; i >= 0; i--){
        int pos = f_findLastInRow(matrix[i], m, k);
        if(pos != -1){
            ans.found = true;
            ans.row = i;
            ans.column = pos;
            return ans;
        }
    }
    return ans;
}

// Recursively finds the first occurrence of k in a sorted row
// Returns the index of the first occurrence or -1 if k is not present
int f_recFindFirstInRow(const std::vector<int>& row, int left, int right, int k){
    if(left > right) return -1;

    int mid = (left + right) / 2;
    if(row[mid] == k){
        int pos = f_recFindFirstInRow(row, left, mid - 1, k);
        if(pos != -1){
            return pos;
        }
        else
            return mid;
    }
    else if(row[mid] < k){
        return f_recFindFirstInRow(row, mid + 1, right, k);
    }
    else 
        return f_recFindFirstInRow(row, left, mid - 1, k);
}

// Recursively checks matrix rows from top to bottom
// and returns the first lexicographical occurrence of k
Result f_recMatrixFirst(const std::vector<std::vector<int>>& matrix, int n, int m, int k, int curRow){
    Result ans;
    ans.found = false;
    ans.row = -1;
    ans.column = -1;
    
    if(curRow >= n) 
        return ans;    

    int pos = f_recFindFirstInRow(matrix[curRow], 0, m - 1, k);
    if(pos != -1){
        ans.found = true;
        ans.row = curRow;
        ans.column = pos;
        return ans;
    }
    return f_recMatrixFirst(matrix, n, m, k, curRow + 1);
}

Result f_recursiveFirst(const std::vector<std::vector<int>>& matrix, int n, int m,int k){
    return f_recMatrixFirst(matrix, n, m, k, 0);
}

// Recursively finds the last occurrence of k in a sorted row
// Returns the index of the last occurrence or -1 if k is not present
int f_recFindLastInRow(const std::vector<int>& row, int left, int right, int k){
    if(left > right) return -1;
    int mid = (left + right) / 2;
    if(row[mid] == k){
        int pos = f_recFindLastInRow(row, mid + 1, right, k);
        if(pos != -1)
            return pos;
        else
            return mid;
    }
    else if(row[mid] < k)
        return f_recFindLastInRow(row, mid + 1, right, k);
    else 
        return f_recFindFirstInRow(row, left, mid - 1, k);
}

// Recursively checks matrix rows from bottom to top
// and returns the last lexicographical occurrence of k
Result f_recMatrixLast(const std::vector<std::vector<int>>& matrix, int n, int m, int k, int curRow){
    Result ans;
    ans.found = false;
    ans.row = -1;
    ans.column = -1;
    
    if(curRow < 0) 
        return ans;    

    int pos = f_recFindLastInRow(matrix[curRow], 0, m - 1, k);
    if(pos != -1){
        ans.found = true;
        ans.row = curRow;
        ans.column = pos;
        return ans;
    }
    return f_recMatrixLast(matrix, n, m, k, curRow - 1);
}

Result f_recursiveLast(const std::vector<std::vector<int>>& matrix, int n, int m,int k){
    return f_recMatrixLast(matrix, n, m, k, n - 1);
}