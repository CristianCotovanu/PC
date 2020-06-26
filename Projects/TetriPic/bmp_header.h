/* Tells the compiler not to add padding for these structs. This may
   be useful when reading/writing to binary files.
   http://stackoverflow.com/questions/3318410/pragma-pack-effect
*/
#pragma pack(1)

typedef struct bmp_fileheader
{
    unsigned char  fileMarker1; /* 'B' */
    unsigned char  fileMarker2; /* 'M' */ 
    unsigned int   bfSize; /* File's size */
    unsigned short unused1;
    unsigned short unused2;
    unsigned int   imageDataOffset; /* Offset to the start of image data */
} bmp_fileheader;

typedef struct bmp_infoheader
{
    unsigned int   biSize; /* Size of the info header - 40 bytes */
    signed int     width; /* Width of the image */
    signed int     height; /* Height of the image */
    unsigned short planes; //owncomm Permanently set to 1
    unsigned short bitPix; //owncomm Permanently set to 24
    unsigned int   biCompression; //owncomm Permanently set to 0
    unsigned int   biSizeImage; /* Size of the image data */
    int            biXPelsPerMeter; //owncomm Permanently set to 0
    int            biYPelsPerMeter; //owncomm Permanently set to 0
    unsigned int   biClrUsed; //owncomm Permanently set to 0
    unsigned int   biClrImportant; //owncomm Permanently set to 0
} bmp_infoheader;

#pragma pack()
