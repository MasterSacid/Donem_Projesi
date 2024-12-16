#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "console.h"
#include "beginning.h"

HANDLE stdOut;

// Create a structure to store message and its delay
typedef struct {
    message* dialog;
    int delay;  // delay in milliseconds
    BOOL clearScreen;  // whether to clear screen after message
} DialogSequence;

// Define all your dialogs
message dialog1[1] = {L"\nOmzundaki deri çantanı sıkıca tutarak taş yoldan ilerliyorsun."};
message dialog2[1] = {L"\nHava serin, ay ışığı önündeki yolu aydınlatıyor. Karşında yükselen devasa kapı,"
                       " üzerinde eski yazıtlar ve yılların yorgunluğunu taşıyan derin çatlaklarla seni bekliyor"};
message dialog3[1] = {L"\nBiraz ilerliyorsun..."};
message dialog4[1] = {L"\nKapının önünde zırhlı bir gardiyan var. "};
message dialog5[1] = {L"\nGardiyan: Dur bakalım! Kimsin ve bu kapıdan geçmek için ne işin var?"};
message dialog6[1] = {L"\nBen sadece bir yolcuyum.Belki de şehrinize birkaç güzel melodi getirmek için buradayım?"};
message dialog7[1] = {L"\nGardiyan seni süzüyor ..."};
message dialog8[1] = {L"\nGardiyan: Bu şehirde melodiler karnımı doyurmaz!Buradan geçmek istiyorsan 100 altın öde!"};
message dialog9[1] = {L"\nKesene hızlıca göz attın\n"};
message dialog10[1]= {L"\nİçinde birkaç bakır para vardı"};
message dialog11[1]= {L"\nhepsi bu."};
message dialog12[1]= {L"..."};
message dialog13[1]= {L"\nSen: 100 altın mı? Bu tam bir soygun! "
                        "\nGardiyan: Burada kuralları ben koyarım. Hadi ya parayı ödersin ya da ..."};
message dialog14[1]={L"\nGardiyanın dikkatini dağıtmak için bir seçim yap\n"
                       "Seçenek 1: Ah, bu nedir? Bir kuş mu pislemiş yoksa zırhınız parlamıyor mu?\n"
                       "Seçenek 2: Oha! O bir örümcek mi yoksa!"};
message dialog15[1]= {L"Ne!  Hani!   Nerede ?"};
message dialog16[1]= {L"\nTüm gücünle koşuyorsun\nGardiyan: Hey! Dur orada! Seni hırsız!\n"
                        "Arkana bile bakmadan dar sokaklara doğru dalıyorsun."};
message dialog17[1]= {L"\nKoşuyorsun"};
message dialog18[1]= {L"\nGözlerin bir çıkış yolu arıyor ve tam o sırada köşedeki eski bir tabelayı fark ettin:"};
message dialog19[1]= {L"\nSarhoş Tilki"};
message dialog20[1] = {L"\nBara girecek misin?\nEvet,Başka seçeneğin yok ki"};
message dialog21[1]= {L"\nİçerisi tütün kokuyor.\nBarmen: Ne arıyorsun burada?  "};
message dialog22[1]= {L"\nSen: Peşimde bir gardiyan var! Lütfen saklanmam gerekiyor!"};
message dialog23[1]= {L"\nBarmen düşünüyor."};
message dialog24[1]= {L"\nSanırsam aklına bir fikir geldi. "};
message dialog25[2]= {L"\nBarmen: Hadi, çabuk ol! Tezgahın altına gir"};
message dialog26[2]= {L"\nHemen tezgâhın altına saklandın. Kısa bir süre sonra kapı açıldı, gardiyan içeri daldı. "};
message dialog27[2]= {L"\nGardiyan: Buraya bir ozan girdi mi? Kıvırcık saçlı, bir lir taşıyor!  r"};
message dialog28[1]= {L"\nBarmen: Burada kimse yok, dostum. Belki diğer sokaklara bakmalısın. "};
message dialog29[1]= {L"\nGardiyan öfkeyle homurdandı, sonra kapıyı çarpıp çıktı. Derin bir nefes aldın, "};
message dialog30[1]= {L"\nancak barmen yüzünde ciddi bir ifadeyle sana doğru eğildi. "};
message dialog31[1]= {L"\nBarmen: Bana borçlusun, ozan. Bütün paranı ver. "};
message dialog32[1]= {L"\nSen: Ama… benim zaten çok az param var!” "};
message dialog33[1]= {L"\nBarmen: O zaman burada kalamazsın. Altınlarını ver, yoksa gardiyana seni ben teslim ederim "};
message dialog34[1]= {L"\nTüm paranı verdin…. "};
message dialog35[1]= {L"\nBarmen, paraları bir kenara koyup başını salladı. "};
message dialog36[1]= {L"\nBarmen: Geceyi burada geçirebilirsin. Ama unutma, bana borçlusun."};
message dialog37[1]= {L"\nUyumaya gittin"};
message dialog38[1]= {L"\nSabah oldu"};
message dialog39[1]= {L"\nBarmenin yanına ilerle"};
message dialog40[1]= {L"..."};
message dialog41[1]= {L"\nSen: AHH!!"};
message dialog42[1]= {L"\nAdam: Seni dün gece gördüm. Gardiyandan kaçarken… etkileyiciydi."};
message dialog43[1]= {L"\nSen: Beni mi izliyordun"};
message dialog44[2]= {L"\nAdam: Bir işim var. İlginizi çekebilir. Ödül büyük. Ama kolay olmayacak."};
message dialog45[2]= {L"\nİlgileniyorsan şu arka masadan beni bulabilirsin"};
message dialog46[2]= {L"\nHiç paran yok."};
message dialog47[2]= {L"\nBunu kabul etmelisin"};






void playDialogSequence(DialogSequence *sequences, int sequenceCount) {
    for (int i = 0; i < sequenceCount; i++) {
        printsAnimated(stdOut, sequences[i].dialog, (COORD){0,0}, 20, "letter");
        Sleep(sequences[i].delay);
        if (sequences[i].clearScreen) {
            system("cls");
        }
    }
}



void beginning() {
    stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");


    DialogSequence sequences[] = {
        {dialog1, 1000, TRUE},
        {dialog2, 2000, TRUE},
        {dialog3, 2000, TRUE},
        {dialog4, 1000, TRUE},
        {dialog5, 1000, TRUE},
        {dialog6, 2000, TRUE},
        {dialog7, 2000, TRUE},
        {dialog8, 2000, TRUE},
        {dialog9, 3000, TRUE},
        {dialog10, 1000,TRUE},
        {dialog11, 3000,TRUE},
        {dialog12,3000,TRUE},
        {dialog13,2000,TRUE},
    };

    DialogSequence sequences2[] = {
        {dialog16, 1000, TRUE},
        {dialog17, 5000, TRUE},
        {dialog18, 2000, TRUE},
        {dialog19, 3000, TRUE},
    };

    DialogSequence sequences3[] = {
        {dialog21, 1000, TRUE},
        {dialog22, 2000, TRUE},
        {dialog23, 2000, TRUE},
        {dialog24, 2000, TRUE},
        {dialog25, 1000, TRUE},
        {dialog26, 1000, TRUE},
        {dialog27, 2000, TRUE},
        {dialog28, 1000, TRUE},
        {dialog29, 1000, TRUE},
        {dialog30, 1000, TRUE},
        {dialog31, 2000, TRUE},
        {dialog32, 1000, TRUE},
        {dialog33, 1000, TRUE},
        {dialog34, 2000, TRUE},
        {dialog35, 2000, TRUE},
        {dialog36, 1000, TRUE},
        {dialog37, 5000, TRUE},
        {dialog38, 2000, TRUE},
        {dialog39, 1000, TRUE},
        {dialog40, 3000, TRUE},
        {dialog41, 1000, TRUE},
        {dialog42, 2000, TRUE},
        {dialog43, 1000, TRUE},
        {dialog44, 1000, TRUE},
        {dialog45, 2000, TRUE},
        {dialog46, 2000, TRUE},
        {dialog47, 1000, TRUE},
    };


    // Calculate the number of sequences
    int sequenceCount = sizeof(sequences) / sizeof(sequences[0]);
    int sequenceCount2 = sizeof(sequences2) / sizeof(sequences2[0]);
    int sequenceCount3 = sizeof(sequences3) / sizeof(sequences3[0]);

    // Play all dialogs
    playDialogSequence(sequences, sequenceCount);
    //Gardiyanın dikkatini dağıtmak için bir şey yap Menüsü geliyor
    printsAnimated(stdOut,dialog14,(COORD){0,0}, 20, "letter");
    Sleep(3000);
    system("cls");

    //Özel diyalog etkisi artsın diye
    printsAnimated(stdOut,dialog15,(COORD){0,0}, 500, "word");
    Sleep(3000);
    system("cls");
    //Continues to play the sequence
    playDialogSequence(sequences2, sequenceCount2);
    //Seçim Menüsü geldi
    printsAnimated(stdOut,dialog20,(COORD){0,0}, 500, "word");
    Sleep(3000);
    system("cls");
    playDialogSequence(sequences3, sequenceCount3);




}