#include <iostream>
using namespace std;

// ��� ������ �Լ�
void flipMatrix(int A[50][50], int row, int col) {
    for (int i = row; i < row + 3; i++) {
        for (int j = col; j < col + 3; j++) {
            A[i][j] = 1 - A[i][j]; // 0�� 1��, 1�� 0���� ������
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int A[50][50];
    int B[50][50];

    // ��� A �Է�
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            A[i][j] = row[j] - '0';
        }
    }

    // ��� B �Է�
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            B[i][j] = row[j] - '0';
        }
    }

    int count = 0;

    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            if (A[i][j] != B[i][j]) {
                flipMatrix(A, i, j);
                count++;
            }
        }
    }

    // A�� B�� �ٸ��ٸ� A�� B�� �����ϰ� ���� �� ����
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] != B[i][j]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << count << endl;

    return 0;
}
