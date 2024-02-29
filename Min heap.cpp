#include<bits/stdc++.h>
using namespace std;

class minHeap {
	private : 
		vector<int> heap;

		int parent(int i) {
			return i-1/2;
		}

		int leftNode(int i) {
			return 2*i+1;
		}

		int rightNode(int i) {
			return 2*i + 2;
		}

	public :
		bool isEmpty() {
			return heap.size() == 0;
		}

		int getSize() {
			return heap.size();
		}

		int getMin() {
			return heap[0];
		}

		void insertNode(int element) {
			heap.push_back(element);
			int ind = heap.size() - 1;

			while(ind > 0) {
				int parentInd = (ind - 1) / 2;
				if(heap[ind] < heap[parentInd]) {
					int temp = heap[parentInd];
					heap[parentInd] = heap[ind];
					heap[ind] = temp;
				} else {
					break;
				}

				ind = parentInd;
			}
		}

		void removeMin() {
			int size = getSize();
			int min = heap[0];

			heap[0] = heap[size - 1];
			heap.pop_back();
			int parentInd = 0;

			while(2*parentInd+1 < size && 2*parentInd+2 < size) {
				int leftChild = 2*parentInd + 1;
				int rightChild = 2*parentInd + 2;

				int minInd = parentInd;
				if(heap[leftChild] < heap[rightChild]) {
					minInd = leftChild;
				} else {
					minInd = rightChild;
				}

				if(heap[parentInd] > heap[minInd]) {
					int temp = heap[minInd];
					heap[minInd] = heap[parentInd];
					heap[parentInd] = temp;
				} else {
					break;
				}

				parentInd = minInd;
			}
		}
};

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	
	int n;
	cin >> n;

	vector<int> a(n);
	minHeap heap1;

	for(int i=0; i<n; i++) {
		cin >> a[i];
		heap1.insertNode(a[i]);
	}

	while(!heap1.isEmpty()) {
		int top = heap1.getMin();
		heap1.removeMin();

		cout << top << " ";
	}
	cout << "\n";
}
