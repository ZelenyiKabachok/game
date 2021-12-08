#ifndef LEVEL_H
#define LEVEL_H

#include "../utility/resources.h"
#include "../utility/list.h"
#include "../objects.h"

//Класс-интерфейс - уровнь.
class ILevel {
public:

//Загрузка уровня.
	virtual void Load() = 0;

//Обновление состояния объектов уровня.
	virtual void UpDate(float delta_time, const bool *pKeys
                , const float angle, float scroll) = 0;

//Отрисовка уровня.
	virtual void Render() = 0;

	virtual ~ILevel() {}
};

#endif
