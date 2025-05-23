#include "Framework.h"

bool GameMath::IsPointBetweenVectors(const Vector2& origin, const Vector2& leftPoint, const Vector2& rightPoint, const Vector2& testPoint)
{
	Vector2 leftDir = leftPoint - origin;
	Vector2 rightDir = rightPoint - origin;

	Vector2 pointDir = testPoint - origin;

	float crossLeft = Vector2::Cross(pointDir, leftDir);
	float crossRight = Vector2::Cross(pointDir, rightDir);

	return crossLeft * crossRight < 0;
}
