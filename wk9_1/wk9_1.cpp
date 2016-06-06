// 在此处补充你的代码
    sort(v.begin(), v.end());
    for( i = v.begin(); i < v.end() ;i ++ )
        for(j = v.begin(); j < v.end() ;j ++ ) {
            //cout << "( " << i->x << " , " << i->y << " ) ; ( " << j->x << " , " << j->y << " ) ";
            if(binary_search(v.begin(),v.end(),Point( j->x, i->y)) &&
                binary_search(v.begin(),v.end(),Point( i->x, j->y)) &&
                (i->x < j->x) &&
                (i->y < j->y) )
                nTotalNum ++;
            //cout << nTotalNum << endl;
        }
    cout << nTotalNum;
