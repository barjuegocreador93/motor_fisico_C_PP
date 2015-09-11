
typedef BITMAP *img;/**Imagenes por direcciones de memoria*/
/**Vector de imagenes*/

char * strTochar(string a)
{
    char * x=new char[a.length()+1];
    strcpy(x,a.c_str());
    return x;
}

class setBitmap
{
   public:
    setBitmap();
    ~setBitmap();
    void create_new_bitmap(int ancho, int largo, int64_t color);
    void mount_bitmap(string dir);
    void print(int iImg,int,int,double pos_x,double pos_y,int largo,int ancho);
    void text_over(int iImg,string text,int ancho_text, int largo_text,int64_t color_text, int64_t color_background);

   protected:
        vector<img>vImg;
};
setBitmap::setBitmap(){

}

setBitmap::~setBitmap(){
    for(int i=0;i<vImg.size();i++)
    {
        destroy_bitmap(vImg[i]);
    }
}


void setBitmap::mount_bitmap(string dir){
    img x;
    vImg.push_back(x);
    vImg[vImg.size()-1]=load_bitmap(strTochar(dir),NULL);
}

void setBitmap::create_new_bitmap(int ancho, int largo, int64_t color)
{
    img x;
    vImg.push_back(x);
    vImg[vImg.size()-1] =  create_bitmap(ancho,largo);
    clear_to_color(vImg[vImg.size()-1],color);
}
void setBitmap::print(int iImg,int a ,int b,double pos_x,double pos_y,int ancho,int largo){
    if(iImg>=0&&iImg<vImg.size())
    blit(vImg[iImg],screen,a,b,pos_x,pos_y,ancho,largo);
}

void setBitmap::text_over(int iImg,string text,int ancho_text, int largo_text,int64_t color_text, int64_t color_background){
    if(iImg>=0&&iImg<vImg.size())
    textout_centre_ex(vImg[iImg], font,strTochar(text),ancho_text,largo_text,color_text,color_background);
}
