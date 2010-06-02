/*!
	@file
	@author		Albert Semenov
	@date		06/2008
*/
/*
	This file is part of MyGUI.

	MyGUI is free software: you can redistribute it and/or modify
	it under the terms of the GNU Lesser General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	MyGUI is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public License
	along with MyGUI.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "MyGUI_Precompiled.h"
#include "MyGUI_SkinItem.h"
#include "MyGUI_FactoryManager.h"
#include "MyGUI_Widget.h"
#include "MyGUI_RenderManager.h"

namespace MyGUI
{
	SkinItem::SkinItem() :
		mTexture(nullptr),
		mText(nullptr),
		mMainSkin(nullptr)
	{
	}

	void SkinItem::_setSkinItemAlign(const IntSize& _size/*, bool _invalidate*/)
	{
		for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin)
			(*skin)->_setAlign(_size/*, _invalidate*/);
	}

	void SkinItem::_setSkinItemVisible(bool _value)
	{
		for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin)
			(*skin)->setVisible(_value);
	}

	void SkinItem::_setSkinItemColour(const Colour& _value)
	{
		for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin)
		{
			ISubWidgetRect* rect = (*skin)->castType<ISubWidgetRect>(false);
			if (rect)
				rect->_setColour(_value);
		}
	}

	void SkinItem::_setSkinItemAlpha(float _value)
	{
		for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin)
			(*skin)->setAlpha(_value);
	}

	void SkinItem::_updateSkinItemView()
	{
		for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin)
			(*skin)->_updateView();
	}

	void SkinItem::_setSkinItemState(const std::string& _state)
	{
		MapWidgetStateInfo::const_iterator iter = mStateInfo.find(_state);
		if (iter == mStateInfo.end())
			return;

		size_t index=0;
		for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin, ++index)
		{
			IStateInfo* data = (*iter).second[index];
			if (data != nullptr)
				(*skin)->setStateData(data);
		}
	}

	void SkinItem::_createSkinItem(ResourceSkin* _info)
	{
		mStateInfo = _info->getStateInfo();

		// ��� ��� � ��������� ����� ���� ��������� � ���� ����� � setRenderItemTexture
		mTextureName = _info->getTextureName();
		mTexture = RenderManager::getInstance().getTexture(mTextureName);

		setRenderItemTexture(mTexture);

		// ��������� ��������� �������
		FactoryManager& factory = FactoryManager::getInstance();
		for (VectorSubWidgetInfo::const_iterator iter=_info->getBasisInfo().begin(); iter!=_info->getBasisInfo().end(); ++iter)
		{
			IObject* object = factory.createObject("BasisSkin", (*iter).type);
			if (object == nullptr)
				continue;

			ISubWidget* sub = object->castType<ISubWidget>();
			sub->_setCroppedParent(static_cast<Widget*>(this));
			sub->setCoord((*iter).coord);
			sub->setAlign((*iter).align);

			mSubSkinChild.push_back(sub);
			addRenderItem(sub);

			// ���� ��������� ����������
			if (mMainSkin == nullptr)
				mMainSkin = sub->castType<ISubWidgetRect>(false);
			if (mText == nullptr)
				mText = sub->castType<ISubWidgetText>(false);
		}

		_setSkinItemState("normal");
	}

	void SkinItem::_deleteSkinItem()
	{
		mTexture = nullptr;

		mStateInfo.clear();

		removeAllRenderItems();
		// ������� ��� ��������
		mMainSkin = nullptr;
		mText = nullptr;

		for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin)
			delete (*skin);
		mSubSkinChild.clear();
	}

	void SkinItem::_setTextureName(const std::string& _texture)
	{
		//if (_texture == mTextureName) return;

		mTextureName = _texture;
		mTexture = RenderManager::getInstance().getTexture(mTextureName);

		setRenderItemTexture(mTexture);
	}

	const std::string& SkinItem::_getTextureName()
	{
		return mTextureName;
	}

} // namespace MyGUI