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
message dialog1[200] = {L"Omzundaki deri çantanı sıkıca tutarak taş yoldan ilerliyorsun."};
message dialog2[400] = {L"Hava serin, ay ışığı önündeki yolu aydınlatıyor. Karşında yükselen devasa kapı\n,"
                       " üzerinde eski yazıtlar ve yılların yorgunluğunu taşıyan derin çatlaklarla seni bekliyor"};
message dialog3[200] = {L"Biraz ilerliyorsun..."};
message dialog4[200] = {L"Kapının önünde zırhlı bir gardiyan var. "};
message dialog5[200] = {L"Gardiyan: Dur bakalım! Kimsin ve bu kapıdan geçmek için ne işin var?"};
message dialog6[200] = {L"Sen: Ben sadece bir yolcuyum.\nBelki de şehrinize birkaç güzel melodi getirmek için buradayım?"};
message dialog7[200] = {L"Gardiyan seni süzüyor ..."};
message dialog8[200] = {L"Gardiyan: Bu şehirde melodiler karnımı doyurmaz!\n Buradan geçmek istiyorsan 100 altın öde!"};
message dialog9[200] = {L"Kesene hızlıca göz attın\n"};
message dialog10[200]= {L"içinde birkaç bakır para vardı"};
message dialog11[200]= {L"hepsi bu."};
message dialog12[200]= {L"..."};
message dialog13[200]= {L"Sen: 100 altın mı? Bu tam bir soygun! "
                        "\nGardiyan: Burada kuralları ben koyarım. Hadi ya parayı ödersin ya da …"};
message dialog14[200]={L"Gardiyanın dikkatini dağıtmak için bir seçim yap\n"
                       "Seçenek 1: Ah, bu nedir? Bir kuş mu pislemiş yoksa zırhınız parlamıyor mu?"
                       "Seçenek 2: Oha! O bir örümcek mi yoksa!"};
message dialog15[200]= {L"Ne!  Hani!   Nerede ?"};
message dialog16[200]= {L"Tüm gücünle koşuyorsun \n Gardiyan: Hey! Dur orada! Seni hırsız!\n"
                        "Arkana bile bakmadan dar sokaklara doğru dalıyorsun."};
message dialog17[200]= {L"Koşuyorsun"};
message dialog18[200]= {L"Gözlerin bir çıkış yolu arıyor ve tam o sırada köşedeki eski bir tabelayı fark ettin:"};
message dialog19[200]= {L"Sarhoş Tilki"};
message dialog20[200] = {L"Bara girecek misin?\n"
                         "Evet\n"
                         "Başka seçeneğin yok ki"};
message dialog21[200]= {L"İçerisi tütün kokuyor. \n Barmen: Ne arıyorsun burada?  "};
message dialog22[200]= {L"Sen: Peşimde bir gardiyan var! Lütfen saklanmam gerekiyor!"};
message dialog23[200]= {L"Barmen düşünüyor."};
message dialog24[200]= {L"Sanırsam aklına bir fikir geldi. "};
message dialog25[200]= {L"Barmen: Hadi, çabuk ol! Tezgahın altına gir"};
message dialog26[200]= {L"Hemen tezgâhın altına saklandın. Kısa bir süre sonra kapı açıldı, gardiyan içeri daldı. "};
message dialog27[200]= {L"Gardiyan: Buraya bir ozan girdi mi? Kıvırcık saçlı, bir lir taşıyor!  r"};
message dialog28[200]= {L"Barmen: Burada kimse yok, dostum. Belki diğer sokaklara bakmalısın. "};
message dialog29[200]= {L"Gardiyan öfkeyle homurdandı, sonra kapıyı çarpıp çıktı. Derin bir nefes aldın, "};
message dialog30[200]= {L"ancak barmen yüzünde ciddi bir ifadeyle sana doğru eğildi. "};
message dialog31[200]= {L"Barmen: Bana borçlusun, ozan. Bütün paranı ver. "};
message dialog32[200]= {L"Sen: Ama… benim zaten çok az param var!” "};
message dialog33[200]= {L"Barmen: O zaman burada kalamazsın. Altınlarını ver, yoksa gardiyana seni ben teslim ederim "};
message dialog34[200]= {L"Tüm paranı verdin…. "};
message dialog35[200]= {L"Barmen, paraları bir kenara koyup başını salladı. "};
message dialog36[200]= {L"Barmen: Geceyi burada geçirebilirsin. Ama unutma, bana borçlusun."};
message dialog37[200]= {L"Uyumaya gittin"};
message dialog38[200]= {L"Sabah oldu"};
message dialog39[200]= {L"Barmenin yanına ilerle"};
message dialog40[200]= {L"..."};
message dialog41[200]= {L"Sen: AHH!!"};
message dialog42[200]= {L"Adam: Seni dün gece gördüm. Gardiyandan kaçarken… etkileyiciydi."};
message dialog43[200]= {L"Sen: Beni mi izliyordun"};
message dialog44[200]= {L"Adam: Bir işim var. İlginizi çekebilir. Ödül büyük. Ama kolay olmayacak."};
message dialog45[200]= {L"İlgileniyorsan şu arka masadan beni bulabilirsin"};
message dialog46[200]= {L"Hiç paran yok."};
message dialog47[200]= {L"Bunu kabul etmelisin"};






void playDialogSequence(DialogSequence* sequences, int sequenceCount) {
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
        {dialog7, 1000, TRUE},
        {dialog8, 5000, TRUE},
        {dialog9, 3000, TRUE},
        {dialog10, 3000,TRUE},
        {dialog11, 5000,TRUE},
        {dialog12,3000,TRUE},
        {dialog13,3000,TRUE},
    };

    DialogSequence sequences2[] = {
        {dialog16, 1000, TRUE},
        {dialog17, 5000, TRUE},
        {dialog18, 2000, TRUE},
        {dialog19, 5000, TRUE},
    };

    DialogSequence sequences3[] = {
        {dialog21, 1000, TRUE},
        {dialog22, 5000, TRUE},
        {dialog23, 2000, TRUE},
        {dialog24, 5000, TRUE},
        {dialog25, 1000, TRUE},
        {dialog26, 1000, TRUE},
        {dialog27, 2000, TRUE},
        {dialog28, 1000, TRUE},
        {dialog29, 1000, TRUE},
        {dialog30, 1000, TRUE},
        {dialog31, 2000, TRUE},
        {dialog32, 1000, TRUE},
        {dialog33, 1000, TRUE},
        {dialog34, 5000, TRUE},
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
        {dialog45, 5000, TRUE},
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