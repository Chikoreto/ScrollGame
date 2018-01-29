#include "Map.hpp"

//コンストラクタ
Map::Map():block_size(32),moved_position(640,352)
{
	//とりあえずブロックサイズの初期化のみ
}

//マップデータのロード(csv)
int Map::Map_Load(int world, int field)
{
	map_scene = 1;		//とりあえず場面1のみ
						//後から場面は最初に全部読み込むようにする
	fail_name = Format(L"DATA/stage_deta/world",world,L"_field", field,L"_",map_scene,L".csv");

	
	//csv読み込み

	map_data_csv.open(fail_name);
	//map_data_csv = CSVReader(fail_name);

	//読み込み失敗ならエラーを返す
	if (!map_data_csv)
	{	return -1;	}

	fail_name = Format(L"DATA/block.png");

	//ブロック画像読み込み
	block_image = Image(fail_name);

	//失敗ならエラー
	if (!block_image)
	{	return -1;}

	//1行目  ワールド、ステージ、場面数なのでとりあえず無視
	//2行目  使用するブロック(テクスチャ)の数
	//3行目  使用するブロックの種類
	//4行目  マップサイズ、w,hの順
	//5行目  以降がマップのブロック配置

	//ブロック数読み込み
	texture_num = map_data_csv.get<int32>(1, 0);

	//マップ情報読み取り
	//w,h数読み込み
	w_max = map_data_csv.get<int32>(3, 0);
	h_max = map_data_csv.get<int32>(3, 1);

	//使用テクスチャID入手
	for (int i = 0; i < texture_num; i++)
	{
		use_texture_num.push_back(map_data_csv.get<int32>(2, i));
	}

	//画像を分割して1ブロック分のテクスチャに変更
	//全テクスチャ分回し、IDと同じ場所のときのみ読み込むようにする
	//ソートされていること前提
	//扉のことはとりあえず考えない(予定では扉は3桁10X見たいな感じにする予定なので)

	block_num_temp = 0;		//現在のブロックIDの位置

	for (int i = 0; i < 100; i++)
	{
		if (use_texture_num[block_num_temp] == i)
		{

			//画像分割
			//                                                  x                   y           w              h
			image.push_back(block_image.clipped((block_size*(i % 10)), (block_size*(i / 10)), block_size, block_size));
			block_texture.push_back(Texture(image[i]));

			//ID配列を1つずらす
			block_num_temp++;

		}
	}


	//ブロックの設定
	//ブロックタイプID、テクスチャ、座標を指定する
	//マス分ループ
	for (int i = 0; i < w_max * h_max; i++)
	{
		int a, b;

		int count_temp = 0;

		//マップに有るブロックのIIDを入手(左上から右下へ)
		map_block_num = map_data_csv.get<int32>((i / w_max) + 4, i % w_max);


		//ID 0(ブロックなし)以外だったらブロック作成
		if (map_block_num > 0)
		{
			//ブロック作成
			//blocks.push_back(Block(map_block_num, block_texture[map_block_num], (i % w_max)*block_size, (i / h_max)*block_size));

			blocks.push_back(Block(map_block_num, image[map_block_num-1], (i % w_max), (i / w_max),block_size));


		}

	}


	map_data_csv.close();
	block_image.clear();

	return 0;
}


//マップ描画
void Map::Map_draw() const
{
	//ブロック数分ループ
	for (int i = 0; i < blocks.size(); i++)
	{
		blocks[i].draw();
	}

}

void Map::update()
{

	block_hit_box.clear();

	//ブロック当たり判定情報をセット
	for (int i = 0; i < blocks.size(); i++)
	{
		blocks[i].update();
		block_hit_box.push_back(blocks[i].get_hit_box());

		//プレイヤー座標もセット
		
		blocks[i].set_moved_position(moved_position);
	}
	
}

Array<Rect> Map::get_block_hit_box()
{
	return block_hit_box;
}

void Map::set_moved_position(Vec2 position)
{
	moved_position = position;

}

