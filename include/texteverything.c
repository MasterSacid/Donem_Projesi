#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct message{
    wchar_t string[128];
    char shown;
    int highlight[8][2];
    char color[8][16];
}message,*pMessage;
{L"kapı",1,NULL,NULL},
message messages[] = {
    {L"Omzundaki deri çantanı sıkıca tutarak taş yoldan ilerliyorsun.\nHava serin, "
     "ay ışığı önündeki yolu aydınlatıyor. \nKarşında yükselen devasa kapı, üzerinde eski "
     "yazıtlar ve yılların "
     "yorgunluğunu taşıyan "
     "derin çatlaklarla seni bekliyor.\nBiraz ilerliyorsun",  1,NULL,NULL},


    {L"Kapının önünde zırhlı bir gardiyan var. ",1,NULL,NULL},

    {L"Gardiyan: Dur bakalım! Kimsin ve bu kapıdan geçmek için ne işin var?",1,NULL,NULL},

    {L"Sen: “Ben sadece bir yolcuyum. Belki de şehrinize birkaç güzel melodi getirmek için buradayım?",1,NULL,NULL},

    {L"Gardiyan seni süzüyor",1,NULL,NULL},

{L"Gardiyan: Bu şehirde melodiler karnımı doyurmaz! Buradan geçmek istiyorsan 100 altın öde!",1,NULL,NULL},

{L" Kesene hızlıca göz attın; içinde birkaç bakır para vardı, hepsi bu. \nSen: 100 altın mı? Bu "
 "tam bir soygun! \nGardiyan: Burada kuralları ben koyarım. Hadi ya parayı ödersin ya da …",1,NULL,NULL},


{L"Gardiyanın dikkatini dağıtmak için bir seçim yap:",1,NULL,NULL}, //BU kısım önemli burada seçim yapılır
{L"Ne!  Hani!   Nerede ? "
 "\n Tüm gücünle koşuyorsun "
 "\n Gardiyan: Hey! Dur orada! Seni hırsız!  ",1,NULL,NULL},

{L"Arkana bile bakmadan dar sokaklara doğru dalıyorsun. \nKoşuyorsun….",1,NULL,NULL},

{L" Gözlerin bir çıkış yolu arıyor ve tam o sırada köşedeki eski bir tabelayı fark ettin: \n"
 "Sarhoş Tilki.",1,NULL,NULL},

{L"Bara girecek misin ?",1,NULL,NULL}, //Seçim yapıyorsun

{L"kapı",1,NULL,NULL},

};




