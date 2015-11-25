= ワークフロー

//comment{
ワークフローは、紙面以外の部分（この本を読む人は書きたいテーマはそろってるだろうから）を中心にRe :VIEWの外野の話（Re:VIEWでは埋められないところを伝えていくかんじかな。
ノンブルとかページ枚数の縛り、B5JとB5の違い、最低限入稿に必要な情報ってかんじ）前回は企画と頒布をフォローしたけど今回はページ数へらすからもうちょっとスコープ絞るのが適切そう。
TeXの話もレイアウト、スタイルみたいなのは飛ばしてしまいたいね。
//}

//comment{
初心者がMacTeXインストールせずに、すこしつかえるようにGrifletのインスタントモードみたいなのほしいね。Dockerファイルでいいんかな？これは思いつき。
//}

本書をここまで読んできて、Re:VIEWのいろはについては概ね諒解していただけたと思います。
この章では、実際に本を作るためのTipsを紹介していきます。
TechBoosterがC81から練り上げてきた本を作るよくできた方法を解説します。

== prhについて

校正支援用ツールとしてprhというツール@<fn>{prh}があります。
prhはproofread helperの略です。
proofreadで1単語だから略したらphだろ！とか言ってはいけません。

#@# prh:disable
prhは単純にルールに従い、文字列を置き換えるだけのものです。
たとえば、「例えば」と書いた時に「たとえば」に置き換えるよう促してくれます。
これをひらがなに「開く」操作といいます。
文章の質を高めるためにはこのような書き換え処理をたくさんこなす必要があるわけです。

TechBoosterでは原稿をみんなが書き終えた後、羊くんが全員の原稿に手を加え、開く処理をいれるなどの作業を行っていました。
そこで、prhを作成し羊の作業から著者個人個人の作業に落とした@<fn>{crazy-mhidaka}わけです。
面白いもので、規則をルール化し記述できるようにしたことで著者の中での校正に対する関心も高まってきました。

肝心の使い方についてです、現状あまりコマンドラインツールとしての使い勝手はよくありません。
language-reviewにはprhが組み込まれているため、language-review経由で使うのが楽でしょう。

まずは、techboosterの設定ファイル（@<href>{https://github.com/vvakame/prh/blob/master/misc/techbooster.yml}）をダウンロードして試してみるのがよいでしょう。
ダウンロードしたファイルをprh.ymlという名前で.reファイルと同じディレクトリに置くとlanguage-reviewが校正用ルールとして利用してくれます。

類似のツールとして、RedPen@<fn>{redpen}やtextlint@<fn>{textlint}などがあります。
さらなる文章の改善を目指すのであれば、これらのツールを利用してみるのもよいでしょう。

とはいえ、根本的に文章の目的と構造がしっかりしていないといくら枝葉末節を補ったところで意味はありません。

//footnote[prh][@<href>{https://github.com/vvakame/prh}]
//footnote[crazy-mhidaka][「羊の労力が減るぞ！」と僕が言ったら、彼は「じゃあもっと作れるな！」って言いました。あたまおかしい。]
//footnote[redpen][@<href>{http://redpen.cc/}]
//footnote[textlint][@<href>{http://efcl.info/2015/09/10/introduce-textlint/}]

== GitHub Oriented Writing

略すとGoW… Gears of Warだ！
ハイ関係ないですね。

TechBoosterがどういう順番で執筆を行っているのか解説します。
TechBoosterは割と大所帯なので、1人だったり、2〜3人でやっているサークルだと少し大げさかもしれませんが参考にはなるでしょう。
大まかな流れは次のとおりです。

 1. 企画会議を行い、1つのIssueに知りたいネタをみんなで書き込む。
 2. オフラインで集合し、ネタの分配や争奪戦を行う。
 3. 1冊=1リポジトリでプライベートリポジトリを作成する。
 4. 1ネタ=1Issue=1章という単位で目次案を書く。
 5. ひたすら書く。masterに直pushでOK。
 6. pull request経由でレビューを受ける。レビューはコメントを使いインラインに書く。
 7. 適当なタイミングでmergeしレビューを請けての修正作業を行う。
 8. あるタイミングで筆者による編集を凍結。羊による校正＆調整作業に入る。必要があれば著者がpull requestを送る。
 9. 入稿作業など。このフェーズからGitHubは利用されなくなる。

プログラマであればご存知のとおり、一箇所にすべての情報が集まっているのが一番効率がよいですし、情報のありかがわからなくてなって困る自体にもなりにくいです。
そのため、ネタ出しから目次の作成、執筆、レビューと手直し、編集までGitHub上で行っています。

//graph[gh-writing][graphviz][よく分かる図解]{
digraph G {
  planning [label="企画"];
  meeting [label="ネタ出し会議"];
  make_repo [label="GitHubにリポジトリ作成"];
  make_index [label="目次案作成"];
  writing [label="バリバリ執筆 & 修正"];
  pr_review [label="レビューをpull requestで送る"];
  merge [label="レビューのmerge"];
  freeze [label="執筆終了"];
  editing [label="編集作業"];
  submit [label="印刷所へ入稿"];

  planning   -> meeting;
  meeting    -> make_repo;
  make_repo  -> make_index;
  make_index -> writing;
  writing    -> pr_review;
  pr_review  -> merge;
  merge      -> writing;
  merge      -> freeze;
  freeze     -> editing;
  editing    -> submit;

  planning [shape=Mdiamond];
  submit [shape=Msquare];
}
//}

いくつか補足します。

 * ひたすら書く。masterに直pushでOK。

これは、同一の.reファイルを複数人で編集する場合が少ないからです。
conflictが発生しないのであればpull requestにする必要性は薄いです。
WIP@<fn>{wip}として、書き終わるまでmasterにmergeしない方法もあります。
しかし、常にmasterで（もちろんビルドが通る状態であることは前提ですが）作業をすると、他の人の進捗もわかりやすく、本全体のページ数も掴みやすく、あまり執筆が進んでいない著者に圧力もかけやすくなります。
執筆というのは著者同士による圧力鍋バトルなので頑張りましょう。
早く書いてまだできていない人に圧力をかけねば自分が圧力をかけられる側に堕ちるのです。

話がそれました。

 * pull request経由でレビューを受ける。レビューはコメントを使いインラインに書く。

@<chapref>{writing-book}でも少し触れましたが、レビューはインラインに.reファイル中に書いてもらいます。
これは、レビュー内容を取り込む時にWebサイトと見比べながら行うのが面倒であること、レビュワー同士で他にどういうコメントがあるかが把握できたほうが学びが多く、指摘の重複も少ないからです。

#@# prh:disable
また、コメントを書いた後直接masterにpushしない理由は、筆者の修正とconflictが発生しやすいためです。
筆者は好きな時に好きなものを書き、気が向いた時にレビューの反映作業を行うのが精神衛生上良いでしょう。
そのためには、conflictなく自由にcommitとpushができる必要があるため、レビュー側のpushはpull requestを通して、となるわけです。

 * あるタイミングで筆者による編集を凍結。羊による校正＆調整作業に入る。必要があれば著者がpull requestを送る。

凍結後にmasterを変更する権限をもつのは編集者（羊）だけです。
執筆者がどうしても修正したい場合、pull requestを送りお伺いを立てます。
これを守らない場合、PDF化した時に改行の具合やら1行あたりの文字数やらを調整しているので羊がぷっぷくぷー！になります。
可哀想なのでやめてあげましょう。

//footnote[wip][Work In Progress つまり書きかけ・作りかけの状態のこと]

== Griflet

TODO mhidaka （ｽｯと担当を変えてみる）

書くことの予定表

 * 専用のCI
 * ビルド環境の準備が不要になる
 ** 一見さんにも優しい

== 入稿

TODO mhidaka

== 紙面構成の話

TODO mhidaka
