

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructRectangle(int area, int* returnSize){
    int *ret = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    memset(ret,0,2);
    int start = sqrt(area);
    int length = start;
    while(length <= area){
        if(area % length != 0){
            length++;
        }
        else break;
    }
    if(length >= area / length){
        ret[0] = length;
        ret[1] = area / length;
    }
    else{
        ret[0] = area / length;
        ret[1] = length;
    }
    return ret;
}