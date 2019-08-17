#ifndef H_EXTENSIONS_CUTEHMI_2_INCLUDE_CUTEHMI_INPLACEERROR_HPP
#define H_EXTENSIONS_CUTEHMI_2_INCLUDE_CUTEHMI_INPLACEERROR_HPP

#include "internal/common.hpp"

#include "Error.hpp"

namespace cutehmi {

/**
 * In-place error.
 *
 * @remark This class is registered as metatype by Initializer instance.
 */
struct CUTEHMI_API InplaceError:
	public Error
{
	// Note: line count starts with 1.
	InplaceError(const QString & message = "Error.", const char * file = nullptr, int line = 0, const char * function = nullptr, int code = Error::FAIL);

	QString str() const;

	QString message;
	const char * file;
	int line;
	const char * function;
};

}

#define CUTEHMI_ERROR(MESSAGE) cutehmi::InplaceError(MESSAGE, __FILE__, __LINE__, Q_FUNC_INFO)

Q_DECLARE_METATYPE(cutehmi::InplaceError)

#endif

//(c)MP: Copyright © 2019, Michal Policht <michpolicht@gmail.com>. All rights reserved.
//(c)MP: This file is a part of CuteHMI.
//(c)MP: CuteHMI is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
//(c)MP: CuteHMI is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
//(c)MP: You should have received a copy of the GNU Lesser General Public License along with CuteHMI.  If not, see <https://www.gnu.org/licenses/>.