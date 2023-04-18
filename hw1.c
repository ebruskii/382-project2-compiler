/* Elizabeth Bruski
 * I pledge my honor that I have abided by the Stevens Honor System.
 * sorting algorithm in task 3: bubble
 * first homework
 */

void strcpy(char *src, char *dst)
{
    // if the string has another character
    // add it to dst
    int i = 0;
L1:
    dst[i] = src[i];
    if (src[i + 1] != '\0')
    { //  the way the line ends
        i++;
        goto L1; // add the copy again
    }
    i++;
    dst[i] = '\0';
}

int dot_prod(char *vec_a, char *vec_b, int length, int size_elem) // is this to a single character>..?
{

    int j = 1; // counter
    int z = 0; // total
L3:
    int k = size_elem;

L2:
    z += ((int)*vec_a) * ((int)*vec_b); // do the multiplication for hte dot product

    k--; // subtract so the size remains
    vec_a++;
    vec_b++;
    if (k > 0) //if the size is bigger than 0
    {
        goto L2; //repeat
    }
    if (j < length)
    {
        j++;
        goto L3; //reset the size element
    }

    return z; //return the total
}

void sort_nib(int *arr, int length)
{
    int ind = 0;
    int total = (8 * length); // total bc 8 digits in the number to sort
    unsigned int all[total];  // new to coput to
    for (int i = 0; i < length; i++)
    { // run for each element
        for (int j = 0; j < 8; j++)
        {                            // run for each hex number
            int nums = 28 - (j * 4); // gets us the first four bits
            unsigned int add = 15 << nums;
            unsigned int one = arr[i] & add; // getting those bits
            unsigned int nib = one >> nums; // bit shift the number by however many bits 
            all[ind] = nib;
            ind++;
        }
    }

    unsigned int min = 0;
    int index = 0;

    for (int i = 0; i < total; i++) //while less than the total
    {
        for (int j = 0; j < total - i - 1; j++) //bubble sort the integers
        {

            if (all[j] > all[j + 1]) // if the element is greater than the one an index above
            { // swap the variables
                unsigned int temp = all[j];
                all[j] = all[j + 1];
                all[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i <length; i++){
        arr[i] = 0;
    }
    int countt = 0;
    for (int i = 0; i < total; i++){ //going through the entire array to split up
        int n = 28 - (4*(i%8)); //in order to find the right amount of characters for proper representation
        unsigned int temp = all[i] << n; //shift back
        arr[countt] += temp; //add temp
        if(i%8 == 7){ //to get right remainder
            countt++;
        }
    }

}

void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second; // trades the places
    *second = temp;   // switches to the temp variable
}

int main()
{
    char str1[] = "382 is the best!";
    char str2[100] = {0};

    strcpy(str1, str2);
    puts(str1);
    puts(str2);

    int vec_a[3] = {12, 34, 10};
    int vec_b[3] = {10, 20, 30};
    int dot = dot_prod((char *)vec_a, (char *)vec_b, 3, sizeof(int));
    printf("%d\n", dot);

    int arr[3] = {0x12BFDA09, 0x9089CDBA, 0x56788910};
    sort_nib(arr, 3);
    for (int i = 0; i < 3; i++)
    {
        printf("0x%08x ", arr[i]);
    }
    puts("");

    return 0;
}
