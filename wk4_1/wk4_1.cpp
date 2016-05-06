char * operator=(const char * s){
	if (s) {
		//r = 0;
		//i = 0;
		char * pchPlus = (char*)strchr(s, '+');
        char * pchEnd = (char*)strchr(s, 'i');
		// only consider good input...
		if ( (pchPlus != NULL) & (pchEnd != NULL)){
			char strReal[pchPlus-s+1];
			strncpy(strReal, s, pchPlus-s);
			strReal[pchPlus - s] = '\0';
			r = atof(strReal);
			char strImg[pchEnd - pchPlus -1];
			strncpy(strImg, pchPlus+1, pchEnd - pchPlus-1);
			strImg[pchEnd - pchPlus -1] = '\0';
			i = atof(strImg);
		}
	}
	return (char*)s;
}