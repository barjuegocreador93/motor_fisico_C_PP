
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
   public
    setBitmap();
    ~setBitmap();
    void create_bitmap(int ancho, int largo);
    void mount_bitmap(string dir);
    void print(int index,int,int,int,int,int largo,int ancho);

   protected
        vector<img>vImg;
   private


};
setBitmap::setBitmap(){

}
void setBitmap::mount_bitmap(string dir){
    img x=load_bitmap(dir,NULL);
    vImg.push_back(x);
}

setBitmap::~setBitmap(){
    for(int i=0;i<vImg.size();i++)
    {
        destroy_bitmap(vImg[i]);
    }
}

