#ifndef LEVEL_H
#define LEVEL_H

#include "../utility/resources.h"
#include "../utility/list.h"
#include "../interface/interface.h"
#include "../objects.h"
#include "../input.h"

//Класс-интерфейс - уровнь.
class ILevel {
public:

//Загрузка уровня.
	virtual void Load(const FT_Face& face, int width, int height) = 0;

//Обновление состояния объектов уровня.
	virtual void UpDate(float delta_time, const Input& input) = 0;

//Отрисовка уровня.
	virtual void Render() = 0;

	virtual ~ILevel() {}
};

#endif
