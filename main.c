#include<stdio.h>
#include<stdlib.h>
//#include"oslabs.h"

#define MAX_ARRAY 10
#define START_CNT 0



// array functions we created
void print_array(int* array_ptr, int array_cnt);

void push_back(int* array_ptr, int* array_cnt, int value);
void push_front(int* array_ptr, int* array_cnt, int value);

void insert_at_index(int* array_ptr, int*array_cnt, int index, int value);
void replace_val_at_index(int* array_ptr,int* array_cnt, int index,int val);
void remove_at_index(int* array_ptr,int* array_cnt,int index);

void sort_array(int* array_ptr, int* array_cnt);



struct person{
    int age_years; //fixed size
    int height_cm; //fixed size
};


int main(){
    int array_cnt = START_CNT;
    int our_array[MAX_ARRAY];

    push_back(our_array,&array_cnt,3);
    push_back(our_array,&array_cnt,2);
    push_back(our_array,&array_cnt,4);

    push_back(our_array,&array_cnt,27);
    push_back(our_array,&array_cnt,2);
    push_back(our_array,&array_cnt,15);



    printf("Push to Back: ");
    print_array(our_array,array_cnt);

    printf("\nPush to Front: ");
    push_front(our_array,&array_cnt, 6);
    print_array(our_array,array_cnt);

    int insert_pos = 4;
    printf("\nInsert at %d: \n",insert_pos);
    insert_at_index(our_array,&array_cnt,insert_pos,5);
    print_array(our_array,array_cnt);

    int remove_pos = 3;
    printf("\nRemove at %d: \n",remove_pos);
    remove_at_index(our_array,&array_cnt,3);
    print_array(our_array,array_cnt);

    int replace_pos = 2;
    int replace_val = 10;
    printf("\nReplace at %d with val %d: \n",replace_pos, replace_val);
    replace_val_at_index(our_array,&array_cnt,replace_pos,replace_val);
    print_array(our_array,array_cnt);

    sort_array(our_array,&array_cnt);
    printf("\nSorted (ascending): ");
    print_array(our_array,array_cnt);


    printf("\n\n=======================================\n\n");

    struct person people_array[MAX_ARRAY];
    int people_cnt = 0;

    struct person joe;
    joe.age_years = 24;
    joe.height_cm = 172;

    struct person lucy;
    lucy.age_years = 36;
    lucy.height_cm = 184;

    struct person alice;
    alice.age_years = 78;
    alice.height_cm = 152;

    struct person bob;
    bob.age_years = 76;
    bob.height_cm = 152;

    struct person cindy;
    cindy.age_years = 18;
    cindy.height_cm = 127;

    people_array[0] = joe;
    people_array[1] = lucy;
    people_array[2] = alice;
    people_array[3] = bob;
    people_array[4] = cindy;

    people_cnt = 5;

    for(int i =0; i <people_cnt; i++){
        printf("Entry: %d\nAge: %d\nHeight: %d\n\n",i,people_array[i].age_years,people_array[i].height_cm);
    }

    int max_age;
    int index = 0;
    max_age = people_array[index].age_years;

    for(int i = 1; i < people_cnt; i++){

        if(people_array[i].age_years > max_age){
            max_age = people_array[i].age_years;
            index = i;
        }

    }

    printf("\nThe oldest person is %d years old. ", max_age);
    printf("They are at index %d.\n",index);
    printf("They are %d centimeters tall.\n",people_array[index].height_cm);



    return 0;
}

void push_back(int* array_ptr, int* array_cnt, int value){
    //do we have space?
    if(*array_cnt < (MAX_ARRAY)){
        array_ptr[*array_cnt] = value;
        (*array_cnt)++;
    } else {
        printf("Cannot push to back! Array is full!\n");
    }
}

void push_front(int* array_ptr, int* array_cnt, int value){
    if(*array_cnt < (MAX_ARRAY)){
        //going from the back, but starting at our array_cnt position

        for(int i = *array_cnt; i > 0; i--){
            array_ptr[i] = array_ptr[i-1];
        }
        array_ptr[0]= value;
        (*array_cnt)++;

    } else {
        printf("Cannot push to front! Array is full!\n");
    }
    return;
}


void insert_at_index(int* array_ptr, int* array_cnt, int index, int value){
    if(
            index<(MAX_ARRAY-1) &&
            index>=0 &&
            index<=*array_cnt &&
            *array_cnt<MAX_ARRAY
            ) {

        //going from the back, but starting at our array_cnt position
        for(int i = *array_cnt; i>= index; i--){
            array_ptr[i] = array_ptr[i-1];
        }

        array_ptr[index] = value;
        (*array_cnt)++;

        //edge case, insertion at end
    } else if (*array_cnt ==(MAX_ARRAY-1) && index == (MAX_ARRAY-1)){
        push_back(array_ptr,array_cnt, value);
    }else if(*array_cnt>= MAX_ARRAY){
        printf("Cannot insert, array is full!\n");
    } else{
        printf("out of bounds!\n");
    }

}

void replace_val_at_index(int* array_ptr,int* array_cnt, int index,int val){

    if(index>=MAX_ARRAY || index <0){
        printf("Out of bounds!\n");
    } else{
        array_ptr[index] = val;
    }
}

void remove_at_index(int* array_ptr,int* array_cnt,int index){
    if(index>=MAX_ARRAY || index <0){
        printf("Out of bounds!\n");
    } else {
        for(int i = index; i <(MAX_ARRAY-1); i++){
            array_ptr[i] = array_ptr[i+1];
        }
        (*array_cnt)--;
    }
}

//selection sort O(n^2)
// we don't need this many variables, but they're used to make explanations easier
void sort_array(int* array_ptr, int* array_cnt){

    int position = 0;
    int min_index = 0;
    int min_val;

    if(*array_cnt>1){

        while(position<*array_cnt){

            min_val = array_ptr[position];
            min_index = position;

            for(int i = position+1; i<*array_cnt; i++){
                if(array_ptr[i]<min_val){
                    min_val = array_ptr[i];
                    min_index = i;
                }
            }

            array_ptr[min_index] = array_ptr[position];
            array_ptr[position] = min_val;

            position++;
        }
    }
}

void print_array(int* array_ptr, int array_cnt){
    printf("[");

    for(int i = 0; i < array_cnt; i++){
        printf("%d",array_ptr[i]);

        if(i<(array_cnt - 1)){
            printf(", ");
        };

    };

    printf("]");
    return;

}
