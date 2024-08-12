#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll k = 1e9;
    string line;
    while (true) {
        ll shift; cin >> shift;
        if (shift == 0) break;

        cin.ignore(100, '\n');
        getline(cin, line);
        for (auto& ch : line) {
            if (ch >= 'a' && ch <= 'z') {
                ll i = ch-'a';
                ch = (k*26 + shift + i) % 26 + 'a';
            } else if (ch >= 'A' && ch <= 'Z') {
                ll i = ch-'A';
                ch = (k*26 + shift + i) % 26 + 'A';
            }
        }
        cout << line << "\n";
    }

    return 0;
}

/*
Liguh ygjylil Dofcom Wuymul qum ihy iz nby zclmn alyun wbuluwnylm iz bcmnils ni yhwlsjn nby gymmuaym ni bcm gcfcnuls wigguhxylm. Uwwilxcha ni bcmnilcuh Auciom Moynihcom: “cz by bux uhsnbcha wihzcxyhncuf ni mus, by qliny cn ch wcjbyl, nbun cm, vs mi wbuhacha nby ilxyl iz nby fynnylm iz nby ufjbuvyn, nbun hin u qilx wiofx vy guxy ion”. Wuymul ufqusm omyx u mbczn iz 3 fynnylm ch nby ufjbuvyn ni nby lcabn. Guhs wyhnolcym bupy jummyx mchwy nby ncgym iz Dofcom Wuymul, mi nby mwcyhwy iz yhwlsjncih bum guxy u nlygyhxiom jlialymm. Zil yrugjfy, u lyguleuvfy lywyhn cgjlipygyhn wihmcmnm ch omcha xczzylyhn mbczn pufoym, chmnyux iz ihfs 3. Qlcny u jlialug nbun, acpyh uh chnyayl hogvyl, H, uhx u nyrn, yhwlsjnm cn vs omcha Wuymul wixcha. Yhwlsjncih mbiofx vy xihy um ziffiqm. Fynnylm zlig ‘U’ ni ‘T’ bupy ni vy mbcznyx H jimcncihm ni nby lcabn, wclwofulfs. Fiqylwumy fynnylm zlig ‘u’ ni ‘t’ ufmi bupy ni vy mbcznyx H jimcncihm ni nby lcabn, wclwofulfs. Nby lymn iz wbuluwnylm xi hin bupy ni vy gixczcyx.
*/