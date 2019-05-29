/*
An implementation of memcpy and memset 
encountered in interview of internship in sangfor
*/

void* memcpy(void* src,void* dst,size_t length)
{
    if(src == NULL || dst == NULL)
        return NULL;
    unsigned char* dst_cpy = (unsigned char*)dst;
    unsigned char* src_cpy = (unsigned char*)src;
    while(length--)
        *dst_cpy-- = *src_cpy--;
    return dst;
}

void* memset(void* dst,int val,size_t length)
{
    void* ret = dst;
    while(length--)
    {
        *dst = (unsigned char)val;
        ++dst; 
    }
    return ret;
}