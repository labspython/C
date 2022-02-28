#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void f(int n, int width, int hight);
int main()
{
    srand(time(NULL));
    int width = 1, hight = 10, n;
    for (int i = 0; i < 1; ++i) {
        n = rand() % (width * hight);
        //cin >> n;
        f(n, width, hight);
    }
    return 0;
}



void f(int const n, int const width, int const hight) {
    int* m_x = new int[n];
    int* m_y = new int[n];
    char* matrix = new char[width * hight];
    for (int i = 0; i < width * hight; ++i)
        matrix[i] = '-';
    srand(time(NULL));
    bool* m_death = new bool[n];
    int death = 0;
    for (int i = 0; i < n; i++) {
        do {
            m_x[i] = rand() % width;
            m_y[i] = rand() % hight;
            //cin >> m_x[i] >> m_y[i];
        } while (matrix[m_y[i] * width + m_x[i]] == '*');
        matrix[m_y[i] * width + m_x[i]] = '*';
        m_death[i] = false;
    }
    for (int i = 0; i < width * hight; i++) {
        if ((i + 1) % width != 0)
            cout << matrix[i] << " ";
        else
            cout << matrix[i] << '\n';
    }
    cout << " " << '\n';
    int counter = 0;
    while (death < n) {
        counter += 1;
        death = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if ((m_x[i] - m_x[j]) * (m_x[i] - m_x[j]) + (m_y[i] - m_y[j]) * (m_y[i] - m_y[j]) == 1) {
                    m_death[i] = m_death[j] = true;
                    matrix[m_y[i] * width + m_x[i]] = 'x';
                    matrix[m_y[j] * width + m_x[j]] = 'x';
                }
        for (int i = 0; i < n; ++i) {
            if (hight != 1 && width != 1) {
                if (m_x[i] * m_y[i] == 0 || m_x[i] == width - 1 || m_y[i] == hight - 1) {
                    m_death[i] = true;
                    matrix[m_y[i] * width + m_x[i]] = 'x';
                }
            }
            else if (hight == 1) {
                if ((m_x[i] == 0) || (m_x[i] == width - 1)) {
                    m_death[i] = true;
                    matrix[m_y[i] * width + m_x[i]] = 'x';
                }
            }
            else {
                if ((m_y[i] == 0) || (m_y[i] == hight - 1)) {
                    m_death[i] = true;
                    matrix[m_x[i] * hight + m_y[i]] = 'x';
                }
            }
        }

        for (int i = 0; i < n; ++i)
            if (m_death[i])
                ++death;
        for (int i = 0; i < n; ++i)
            if (m_death[i] == false) {
                if (hight != 1 && width != 1) {
                    int mov = rand() % 4;
                    if (mov == 0) {
                        matrix[(m_y[i]--) * width + m_x[i]] = '-';
                        if (matrix[m_y[i] * width + m_x[i]] == '*')
                            ++m_y[i];
                        matrix[m_y[i] * width + m_x[i]] = '*';
                    }
                    else if (mov == 1) {
                        matrix[m_y[i] * width + (m_x[i]++)] = '-';
                        if (matrix[m_y[i] * width + m_x[i]] == '*')
                            --m_x[i];
                        matrix[m_y[i] * width + m_x[i]] = '*';
                    }
                    else if (mov == 2) {
                        matrix[m_y[i] * width + (m_x[i]--)] = '-';
                        if (matrix[m_y[i] * width + m_x[i]] == '*')
                            ++m_x[i];
                        matrix[m_y[i] * width + m_x[i]] = '*';
                    }
                    else if (mov == 3) {
                        matrix[(m_y[i]++) * width + m_x[i]] = '-';
                        if (matrix[m_y[i] * width + m_x[i]] == '*')
                            --m_y[i];
                        matrix[m_y[i] * width + m_x[i]] = '*';
                    }
                }
                else if (hight == 1) {
                    int mov = rand() % 2;
                    if (mov == 0) {
                        matrix[m_y[i] * width + (m_x[i]++)] = '-';
                        if (matrix[m_y[i] * width + m_x[i]] == '*')
                            --m_x[i];
                        matrix[m_y[i] * width + m_x[i]] = '*';
                    }

                    if (mov == 1) {
                        matrix[m_y[i] * width + (m_x[i]--)] = '-';
                        if (matrix[m_y[i] * width + m_x[i]] == '*')
                            ++m_x[i];
                        matrix[m_y[i] * width + m_x[i]] = '*';
                    }
                }
                else if (width == 1) {
                    int mov = rand() % 2;
                    if (mov == 0) {
                        matrix[m_x[i] * hight + (m_y[i]++)] = '-';
                        if (matrix[m_x[i] * hight + m_y[i]] == '*')
                            --m_y[i];
                        matrix[m_x[i] * hight + m_y[i]] = '*';
                    }

                    if (mov == 1) {
                        matrix[m_x[i] * hight + (m_y[i]--)] = '-';
                        if (matrix[m_x[i] * hight + m_y[i]] == '*')
                            ++m_y[i];
                        matrix[m_x[i] * hight + m_y[i]] = '*';
                    }
                }
            }
        for (int i = 0; i < width * hight; i++) {
            if ((i + 1) % width != 0)
                cout << matrix[i] << " ";
            else
                cout << matrix[i] << '\n';
        }
        cout << counter << endl;
    }
}
