int InRectangle (float pt[2], float rect[4]){
    float smallX = 0; 
    float bigX = 0;
    float smallY = 0;
    float bigY = 0;
    if(rect[0]>rect[2]){
        bigX = rect[0];
        smallX = rect [2]; 
    }
    else{
        bigX = rect[2];
        smallX = rect [0]; 
    }
    if(rect[1]>rect[3]){
        bigY = rect[1];
        smallY = rect [3]; 
    }
    else{
        bigY = rect[3];
        smallY = rect [1]; 
    }
    if(pt[0]<smallX || pt[0]>bigX){
        return 0;
    }
    if(pt[1]<smallY || pt[1]>bigY){
        return 0;
    }
    return 1;
}