 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "../include/console.h"
#include "../include/narrative.h"



void beginning() {
    HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE stdIn = GetStdHandle(STD_INPUT_HANDLE);
    dialog dialogues1[]={
        {{L"\nOmzundaki deri çantanı sıkıca tutarak taş yoldan ilerliyorsun."},1000,1},
        {{L"\nHava serin, ay ışığı önündeki yolu aydınlatıyor. Karşında yükselen devasa kapı, üzerinde eski yazıtlar ve yılların yorgunluğunu taşıyan derin çatlaklarla seni bekliyor"},1000,1},
        {{L"\nBiraz ilerliyorsun..."},1000,1},
        {{L"\nKapının önünde zırhlı bir gardiyan var."},1000,1},
        {{L"\nGardiyan: Dur bakalım! Kimsin ve bu kapıdan geçmek için ne işin var?"},1000,1},
        {{L"\nBen sadece bir yolcuyum.Belki de şehrinize birkaç güzel melodi getirmek için buradayım?"},1000,1},
        {{L"\nGardiyan seni süzüyor ..."},1000,1},
        {{L"\nGardiyan: Bu şehirde melodiler karnımı doyurmaz!Buradan geçmek istiyorsan 100 altın öde!"},1000,1},
        {{L"\nKesene hızlıca göz attın\n"},1000,1},
         {{L"\nİçinde birkaç bakır para vardı"},1000,1},
        {{L"\nhepsi bu."},1000,1},
        {{L"..."},1000,1},
        {{L"\nSen: 100 altın mı? Bu tam bir soygun!\nGardiyan:"
          "Burada kuralları ben koyarım. Hadi ya parayı ödersin ya da ..."},1000,1},

        {{L"\0"},10,1}
    };



    printSequence(stdOut,dialogues1);

    wchar_t sorgu1[] = {L"Gardiyanın dikkatini dağıtmak için bir seçim yap"};
    wchar_t secenekler1[2][300] = {
        L"Seçenek1:Ah, bu nedir? Bir kuş mu pislemiş yoksa zırhınız parlamıyor mu?",
        L"Seçenek2:Oha! O bir örümcek mi yoksa!",
    };
    dialogChoice(stdOut,stdIn,sorgu1,secenekler1,2);

    system("cls");
   //pMessage dialog2= {{L"Ne!  Hani!   Nerede ?"}};
   // printsAnimated(stdOut,&dialog2.,(COORD){0,0},300,"word");



}




/*

dialog1 = {L"\nOmzundaki deri çantanı sıkıca tutarak taş yoldan ilerliyorsun."};
 dialog2 = {L"\nHava serin, ay ışığı önündeki yolu aydınlatıyor. Karşında yükselen devasa kapı, üzerinde eski yazıtlar ve yılların yorgunluğunu taşıyan derin çatlaklarla seni bekliyor"};
 dialog3 = {L"\nBiraz ilerliyorsun..."};
 dialog4 = {L"\nKapının önünde zırhlı bir gardiyan var. "};
 dialog5 = {L"\nGardiyan: Dur bakalım! Kimsin ve bu kapıdan geçmek için ne işin var?"};
 dialog6 = {L"\nBen sadece bir yolcuyum.Belki de şehrinize birkaç güzel melodi getirmek için buradayım?"};
 dialog7 = {L"\nGardiyan seni süzüyor ..."};
 dialog8 = {L"\nGardiyan: Bu şehirde melodiler karnımı doyurmaz!Buradan geçmek istiyorsan 100 altın öde!"};
 dialog9 = {L"\nKesene hızlıca göz attın\n"};
 dialog10= {L"\nİçinde birkaç bakır para vardı"};
 dialog11= {L"\nhepsi bu."};
 dialog12= {L"..."};
 dialog13= {L"\nSen: 100 altın mı? Bu tam bir soygun! "
      "\nGardiyan: Burada kuralları ben koyarım. Hadi ya parayı ödersin ya da ..."};
 dialog14={L"\nGardiyanın dikkatini dağıtmak için bir seçim yap\n"
     "Seçenek 1: Ah, bu nedir? Bir kuş mu pislemiş yoksa zırhınız parlamıyor mu?\n"
     "Seçenek 2: Oha! O bir örümcek mi yoksa!"};
 dialog15= {L"Ne!  Hani!   Nerede ?"};
 dialog16= {L"\nTüm gücünle koşuyorsun\nGardiyan: Hey! Dur orada! Seni hırsız!\n"
             "Arkana bile bakmadan dar sokaklara doğru dalıyorsun."};
= {L"\nKoşuyorsun"};
= {L"\nGözlerin bir çıkış yolu arıyor ve tam o sırada köşedeki eski bir tabelayı fark ettin:"};
= {L"\nSarhoş Tilki"};
 = {L"\nBara girecek misin?\nEvet,Başka seçeneğin yok ki"};
= {L"\nİçerisi tütün kokuyor.\nBarmen: Ne arıyorsun burada?  "};
= {L"\nSen: Peşimde bir gardiyan var! Lütfen saklanmam gerekiyor!"};
= {L"\nBarmen düşünüyor."};
= {L"\nSanırsam aklına bir fikir geldi. "};
= {L"\nBarmen: Hadi, çabuk ol! Tezgahın altına gir"};
= {L"\nHemen tezgâhın altına saklandın. Kısa bir süre sonra kapı açıldı, gardiyan içeri daldı. "};
= {L"\nGardiyan: Buraya bir ozan girdi mi? Kıvırcık saçlı, bir lir taşıyor!  r"};
= {L"\nBarmen: Burada kimse yok, dostum. Belki diğer sokaklara bakmalısın. "};
= {L"\nGardiyan öfkeyle homurdandı, sonra kapıyı çarpıp çıktı. Derin bir nefes aldın, "};
= {L"\nancak barmen yüzünde ciddi bir ifadeyle sana doğru eğildi. "};
= {L"\nBarmen: Bana borçlusun, ozan. Bütün paranı ver. "};
= {L"\nSen: Ama… benim zaten çok az param var!” "};
= {L"\nBarmen: O zaman burada kalamazsın. Altınlarını ver, yoksa gardiyana seni ben teslim ederim "};
= {L"\nTüm paranı verdin…. "};
= {L"\nBarmen, paraları bir kenara koyup başını salladı. "};
= {L"\nBarmen: Geceyi burada geçirebilirsin. Ama unutma, bana borçlusun."};
= {L"\nUyumaya gittin"};
= {L"\nSabah oldu"};
= {L"\nBarmenin yanına ilerle"};
= {L"..."};
= {L"\nSen: AHH!!"};
= {L"\nAdam: Seni dün gece gördüm. Gardiyandan kaçarken… etkileyiciydi."};
= {L"\nSen: Beni mi izliyordun"};
= {L"\nAdam: Bir işim var. İlginizi çekebilir. Ödül büyük. Ama kolay olmayacak."};
= {L"\nİlgileniyorsan şu arka masadan beni bulabilirsin"};
= {L"\nHiç paran yok."};
= {L"\nBunu kabul etmelisin"};


*/