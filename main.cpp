#include <iostream>
#include <vector>



void generateArray(std::vector<int> & array, int size){
    for (int i = 0; i < size; i ++){
        int v1 = rand() % 100;
        array.emplace_back(v1);
    }
}

bool isSorted(std::vector<int> & array, int start, int fin){
    for(int i = start;i < fin; i++){
        if(array[i] > array[i+1]){
            return false;
        }
    }
    return true;
}

void quickSort(std::vector<int> & array, int index, int pivot){
    if(!isSorted(array,index,pivot)){
        if(array[index] > array[pivot]){
            if(index + 1 == pivot){
                int tmp = array[index];
                array[index] = array[pivot];
                array[pivot] = tmp;
                pivot = pivot - 1;
                index = 0;
            }
            else{
                // changing position pivot to left
                int tmpPivot = array[pivot-1];
                array[pivot-1] = array[pivot];
                // getting the number left side of pivot to the position of index
                int tmpI = array[index];
                array[index] = tmpPivot;
                // getting the index to the right side of pivot because it is greater than it.
                array[pivot] = tmpI;
                pivot--;
                quickSort(array,index,pivot);
            }
        }
        else if(index < array.size()){
            index++;
            quickSort(array,index,pivot);
        }

        if (index < pivot){
            quickSort(array,0,pivot-1);
            quickSort(array, pivot , array.size()-1);
        }
    }
}


int main() {
    int sizeOfArray = 100;
    std::vector<int> array;
    generateArray(array,sizeOfArray);

    for (int i = 0; i < sizeOfArray; i ++){
        std::cout<<array[i]<<" ";
    }

    std::cout<<std::endl<<std::endl;
    quickSort(array, 0, sizeOfArray-1);
    std::cout<<std::endl;

    for (int i = 0; i < sizeOfArray; i ++){
        std::cout<<array[i]<<" ";
    }
    return 0;
}
