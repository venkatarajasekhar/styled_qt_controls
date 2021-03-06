/**************************************************************************************
**
** Copyright (C) 2016 Bernhard Steiner
**
** This file is part of the styled_qt_controls library
**
** This product is licensed under the GNU General Public License version 3.
** The license is as published by the Free Software Foundation published at
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** Alternatively, this product is licensed under the GNU Lesser General Public
** License version 3 for non-commercial use. The license is as published by the
** Free Software Foundation published at https://www.gnu.org/licenses/lgpl-3.0.html.
**
** Feel free to contact us if you have any questions about licensing or want
** to use the library in a commercial closed source product.
**
**************************************************************************************/

#pragma once

#include "..\styled_qt_controls.hpp"

BEGIN_BDL_SQTC

namespace util
{
	/*! \brief Loads and parses qt stylesheet files
		*
		* \author bdl
		*
		* Loads a file from the ressources and parses it for theme_color constants. All colors from theme_colors can be used with the "@[COLOR_NAME]" syntax.
		*/
	class BDL_SQTC_EXPORT style_loader
	{
		typedef QList<QPair<QString, QString>> string_string_hashtable;
		PROPERTY0(string_string_hashtable, replacements);
		PROPERTY0(QString, original_text);

	public:
		/*! \brief Initializes a new instance of the style_loader class
			*
			* \param path The first file to load here
			*/
		style_loader(QString path);
		/*! \brief Releases all data associated with an instance of the style_loader class
			*/
		~style_loader();

		/*! \brief Appends a file to the style string
			*
			* \param path Path to the file
			*/
		void append_file(QString path);
		/*! \brief Parses and returns the style string
			*
			* \returns The parsed style string
			*/
		QString style_string() const;

		/*! \brief Converts a QColor to a QString in the format rgba(R,G,B,A)
			*
			* \param color The color
			*
			* \returns The resulting string
			*/
		static QString color_to_text(QColor color);

	private:
		void set_replacement(QString key, QColor color);
	};
}

END_BDL_SQTC