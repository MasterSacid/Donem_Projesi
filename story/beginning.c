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

    dialog dialogues2[]={
    {{L"\nTüm gücünle koşuyorsun\nGardiyan: Hey! Dur orada! Seni hırsız!"},1000,1},
    {{L"\nArkana bile bakmadan dar sokaklara gidiyorsun"},1000,1},
    {{L"\nKoşuyorsun"},1000,1},
    {{L"\nGözlerin bir çıkış yolu arıyor ve tam o sırada köşedeki eski bir tabelayı fark ettin:"},1000,1},
    {{L"\nSarhoş Tilki"},3000,1},
    {{L"\0"},10,1}
    };

    dialog dialogues3[]={
        {{L"\nİçerisi tütün kokuyor."},1000,1},
        {{L"\nSen: Peşimde bir gardiyan var! Lütfen saklanmam gerekiyor!"},1000,1},
        {{{L"\nBarmen düşünüyor."}},1000,1},
        {{L"\nSanırsam aklına bir fikir geldi. "},1000,1},
        {{L"\nBarmen: Hadi, çabuk ol! Tezgahın altına gir"},1000,1},
        {{L"\nHemen tezgâhın altına saklandın. Kısa bir süre sonra kapı açıldı, gardiyan içeri daldı."},1000,1},
        {{L"\nGardiyan: Buraya bir ozan girdi mi? Kıvırcık saçlı, bir lir taşıyor!"},1000,1},
        {{L"\nBarmen: Burada kimse yok, dostum. Belki diğer sokaklara bakmalısın. "},1000,1},
        {{L"\nGardiyan öfkeyle homurdandı, sonra kapıyı çarpıp çıktı. Derin bir nefes aldın, "},1000,1},
        {{L"\nancak barmen yüzünde ciddi bir ifadeyle sana doğru eğildi. "},1000,1},
        {{L"\nBarmen: Bana borçlusun, ozan. Bütün paranı ver. "},1000,1},
        {{L"\nSen: Ama… benim zaten çok az param var!"},1000,1},
        {{L"\nBarmen: O zaman burada kalamazsın. Altınlarını ver, yoksa gardiyana seni ben teslim ederim "},1000,1},
        {{L"\nUyumaya gittin "},1000,1},
        {{L"\nSabah oldu"},1000,1},

        {{L"\0"},10,1}
    };

    dialog dialogues4[]={
        {{L"\n..."},1000,1},
        {{L"\nSen:AHHH"},1000,1},
        {{L"\nAdam: Seni dün gece gördüm. Gardiyandan kaçarken… etkileyiciydi."},1000,1},
        {{L"\nSen: Beni mi izliyordun ?"},1000,1},
        {{L"\nAdam: Bir işim var. İlginizi çekebilir. Ödül büyük. Ama kolay olmayacak."},3000,1},
        {{L"\nİlgileniyorsan şu arka masadan beni bulabilirsin"},1000,1},
        {{L"\nHiç paran yok."},3000,1},
        {{L"\nBunu kabul etsen iyi olur"},3000,1},



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
   message dialog2= {{L"Ne!  Hani!   Nerede ?"}};
    printsAnimated(stdOut,&dialog2,(COORD){0,0},300,"word");
    system("cls");

   printSequence(stdOut,dialogues2);
    wchar_t sorgu2[] = {L"Bara girecek misin"};
    wchar_t secenekler2[2][300] = {
        L"Evet",
        L"Başka bir seçeneğin yok ki zaten :(",
    };
    dialogChoice(stdOut,stdIn,sorgu2,secenekler2,2);
    system("cls");

    printSequence(stdOut,dialogues3);

    wchar_t sorgu3[] = {L"Uyandın"};
    wchar_t secenekler3[1][300] = {
        L"Barmenin yanına git"
    };
    system("cls");

    printSequence(stdOut,dialogues4);



}




/*



= {L"\nİçerisi tütün kokuyor.\nBarmen: Ne arıyorsun burada?  "};
= {L"\nSen: Peşimde bir gardiyan var! Lütfen saklanmam gerekiyor!"};
= ;
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