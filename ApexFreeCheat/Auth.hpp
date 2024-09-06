#include <ctime>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <windows.h>
#include <winhttp.h>
#include <iostream>

#pragma comment(lib, "winhttp.lib")

namespace Auth
{
    std::string PerformPostRequest(const std::wstring& server, const std::wstring& path, const std::string& activationCode) {
        HINTERNET hSession = NULL, hConnect = NULL, hRequest = NULL;
        DWORD dwSize = 0;
        DWORD dwDownloaded = 0;
        LPSTR pszOutBuffer;
        BOOL  bResults = FALSE;
        std::string responseData;

        // Create the JSON payload with the activation code
        std::string jsonPayload = R"({"token": ")" + activationCode + R"("})";

        // Initialize WinHTTP
        hSession = WinHttpOpen(L"A WinHTTP Example Program/1.0",
            WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
            WINHTTP_NO_PROXY_NAME,
            WINHTTP_NO_PROXY_BYPASS,
            0);
        if (!hSession) {
            std::cerr << "WinHttpOpen failed\n";
            return "";
        }

        // Specify the server
        hConnect = WinHttpConnect(hSession, server.c_str(),
            INTERNET_DEFAULT_HTTPS_PORT, 0);
        if (!hConnect) {
            std::cerr << "WinHttpConnect failed\n";
            WinHttpCloseHandle(hSession);
            return "";
        }

        // Create the request
        hRequest = WinHttpOpenRequest(hConnect, L"POST", path.c_str(),
            NULL, WINHTTP_NO_REFERER,
            WINHTTP_DEFAULT_ACCEPT_TYPES,
            WINHTTP_FLAG_SECURE);
        if (!hRequest) {
            std::cerr << "WinHttpOpenRequest failed\n";
            WinHttpCloseHandle(hConnect);
            WinHttpCloseHandle(hSession);
            return "";
        }

        // Set options to ignore SSL certificate errors (optional, use with caution in production)
        DWORD dwFlags = SECURITY_FLAG_IGNORE_UNKNOWN_CA |
            SECURITY_FLAG_IGNORE_CERT_DATE_INVALID |
            SECURITY_FLAG_IGNORE_CERT_CN_INVALID |
            SECURITY_FLAG_IGNORE_CERT_WRONG_USAGE;

        //WinHttpSetOption(hRequest, WINHTTP_OPTION_SECURITY_FLAGS, &dwFlags, sizeof(dwFlags));

        // Set headers
        std::wstring headers = L"Content-Type: application/json\r\n";
        WinHttpAddRequestHeaders(hRequest, headers.c_str(), -1L, WINHTTP_ADDREQ_FLAG_ADD);

        // Send the request
        bResults = WinHttpSendRequest(hRequest,
            WINHTTP_NO_ADDITIONAL_HEADERS,
            0,
            (LPVOID)jsonPayload.c_str(),
            jsonPayload.size(),
            jsonPayload.size(),
            0);
        if (!bResults) {
            std::cerr << "WinHttpSendRequest failed\n";
            WinHttpCloseHandle(hRequest);
            WinHttpCloseHandle(hConnect);
            WinHttpCloseHandle(hSession);
            return "";
        }

        // Receive the response
        bResults = WinHttpReceiveResponse(hRequest, NULL);
        if (!bResults) {
            std::cerr << "WinHttpReceiveResponse failed\n";
            WinHttpCloseHandle(hRequest);
            WinHttpCloseHandle(hConnect);
            WinHttpCloseHandle(hSession);
            return "";
        }

        // Read the response
        do {
            dwSize = 0;
            if (!WinHttpQueryDataAvailable(hRequest, &dwSize)) {
                std::cerr << "WinHttpQueryDataAvailable failed\n";
                break;
            }

            pszOutBuffer = new char[dwSize + 1];
            if (!pszOutBuffer) {
                std::cerr << "Out of memory\n";
                break;
            }

            ZeroMemory(pszOutBuffer, dwSize + 1);

            if (!WinHttpReadData(hRequest, (LPVOID)pszOutBuffer, dwSize, &dwDownloaded)) {
                std::cerr << "WinHttpReadData failed\n";
            }
            else {
                responseData.append(pszOutBuffer, dwDownloaded);
            }

            delete[] pszOutBuffer;
        } while (dwSize > 0);

        // Clean up
        WinHttpCloseHandle(hRequest);
        WinHttpCloseHandle(hConnect);
        WinHttpCloseHandle(hSession);

        return responseData;
    }

    bool auth(std::string j8_code)
    {
        if (j8_code.empty())
        {
            return false;
        }

        std::wstring server = L"apex.hhhhhi.com";  // e.g., L"example.com"
        std::wstring path = L"/check";

        std::string response = PerformPostRequest(server, path, j8_code);

        if (response.find("\"success\"") == std::string::npos) {
            std::cout << response << "\n";
            return false;
        }
        return true;
    }
}