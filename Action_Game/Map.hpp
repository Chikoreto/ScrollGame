#ifndef MAP_H
#define MAP_H

#include <Siv3D.hpp>
#include "Block.hpp"

class Map
{
private:
	Array<Block> blocks;					//マップの全ブロック
	Array<Texture> block_texture;			//使用するブロックのテクスチャ
	Array<int> use_texture_num;				//使用するテクスチャのID
	Array<Rect> block_hit_box;				//ブロックの当たり判定格納

	CSVReader map_data_csv;					//マップデータ読み込み
	int w_max, h_max;						//マップの最大マス数
	int texture_num;						//読み込むテクスチャの数
	int map_scene;							//マップの場面
	FilePath fail_name;						//読み込みファイルの名前
	Image block_image;						//全部ロック画像読み込み切り取ってテクスチャに入れる
	const int block_size;					//ブロックのサイズ(32固定)
	int block_num_temp;						//ブロックID変数時に現在のブロック数を表す
	int map_block_num;						//csvファイルから読み込んだそのマップで使う１ブロックのIDブロックの初期化にしか使わないため使いまわす

	Vec2 moved_position;					//ブロックの移動距離計算用座標(プレイヤーの座標)

	Array<Image> image;

public:
	Map::Map();								//コンストラクタ
	int Map_Load(int world,int field);		//マップデータのロード
	void update();							//更新

	void Map_draw() const;						//map描画
	Array<Rect> get_block_hit_box();

	void set_moved_position(Vec2 position);
};


#endif     //include guard : MAP_H