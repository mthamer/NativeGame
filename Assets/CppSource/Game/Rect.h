#pragma once

namespace MyGame {

	template <typename T>
	struct Point
	{
		T x;
		T y;

		Point() {}
		Point(T px, T py) { x = px; y = py; }
	};

	//
	// Note: +X axis goes left->right, +Y axis goes bottom->top
	//
	template <typename T>
	struct Rectangle
	{
	public:
		typedef Point<T> PointType;

		PointType mTopLeft;
		PointType mBottomRight;

		Rectangle() {}
		Rectangle(const PointType &topLeft, const PointType &bottomRight)
		{
			mTopLeft = topLeft;
			mBottomRight = bottomRight;
		}

		bool Contains(const PointType& pPoint)
		{
			return !(pPoint.x < mTopLeft.x) && (pPoint.x < mBottomRight.x) &&
				!(pPoint.y < mTopLeft.y) && (pPoint.y < mBottomRight.y);
		}

		T GetWidth(void) const
		{
			return mBottomRight.x - mTopLeft.x;
		}

		T GetHeight(void) const
		{
			return mTopLeft.y - mBottomRight.x;
		}

		bool Intersect(const Rectangle<T> &RectB) const
		{
			return (mTopLeft.x < RectB.mBottomRight.x && mBottomRight.x > RectB.mTopLeft.x &&
				mTopLeft.y > RectB.mBottomRight.y && mBottomRight.y < RectB.mTopLeft.y);
		}
	};
}